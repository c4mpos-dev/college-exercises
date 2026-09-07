"""
-----------------------------------------------------------------------
CLIENTE DE CHAT VIA SOCKET TCP
-----------------------------------------------------------------------
Trabalho de Redes de Computadores
Grupo   : 12 (Cauã Campos e Ana Clara Castilho)

Base que a gente usou (material que o professor deu):
"client.c" / "cliente.cpp", na pasta /original: conecta, manda UMA
frase pronta, recebe UMA resposta e fecha o programa.
Referencia: https://docs.python.org/3/library/socket.html

O que a gente implementou de novo:
[1] Conversa CONTINUA, em vez de mandar uma mensagem e acabar
[2] Uma THREAD so pra RECEBER. Assim da pra receber mensagem de
    outra pessoa enquanto voce ainda ta digitando a sua (o original
    era travado: mandava, esperava, so dai fazia outra coisa)
[3] Manda o APELIDO pro servidor assim que conecta
[4] IP e porta configuravel direto na linha de comando
[5] Fecha tudo direitinho com /sair ou Ctrl+C
[6] Cada mensagem que chega mostra a HORA (data + horario) de quando
    foi recebida, tipo um chat de verdade
[7] Cores no terminal diferentes pra cada tipo de mensagem (privada,
    sistema, entrada/saida, arquivo), facilita enxergar na tela
[8] Comando /enviararquivo - manda um arquivo pequeno pra outro
    cliente, o servidor so repassa e quem recebe salva na pasta
    "recebidos"
-----------------------------------------------------------------------
"""

import base64
import os
import socket
import sys
import threading
from datetime import datetime

# ### MODIFICACAO DO GRUPO [7] ### - habilita cor no console do Windows
# Sem isso, o cmd/PowerShell antigo mostra os codigos de cor como texto
# literal (tipo "[93m") em vez de pintar a letra.
if sys.platform == "win32":
    import ctypes
    _kernel32 = ctypes.windll.kernel32
    _kernel32.SetConsoleMode(_kernel32.GetStdHandle(-11), 7)

RESET = "\033[0m"
COR_SISTEMA = "\033[93m"    # amarelo - avisos do servidor (***)
COR_PRIVADO = "\033[95m"    # magenta - mensagem privada
COR_ENTROU = "\033[92m"     # verde - alguem entrou na sala
COR_SAIU = "\033[91m"       # vermelho - alguem saiu da sala
COR_ARQUIVO = "\033[96m"    # ciano - arquivo enviado/recebido

# ------------------------------------------------------------------
# CONFIGURACOES PADRAO (da pra trocar passando argumento na linha de comando)
# ------------------------------------------------------------------
HOST_PADRAO = "127.0.0.1"   # 127.0.0.1 = a propria maquina (localhost)
PORTA_PADRAO = 5000
BUFFER = 1024
PASTA_RECEBIDOS = "recebidos"           # ### MODIFICACAO DO GRUPO [8] ###
MAX_TAMANHO_ARQUIVO = 2 * 1024 * 1024   # 2 MB, de boa pra demonstracao

# Avisa pra thread que fica recebendo que o programa ta terminando
encerrando = threading.Event()


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [8] ### - salva um arquivo recebido de outro cliente
# ------------------------------------------------------------------
def salvar_arquivo_recebido(linha):
    """
    A linha chega no formato @@ARQUIVO@@remetente@@nome@@dados_base64.
    Decodifica e grava dentro da pasta "recebidos". Devolve o texto que
    vai aparecer na tela avisando o que aconteceu.
    """
    partes = linha.split("@@")
    if len(partes) < 5:
        return "*** Chegou um arquivo com formato invalido. ***"

    remetente, nome, conteudo_b64 = partes[2], partes[3], partes[4]
    try:
        dados = base64.b64decode(conteudo_b64)
    except (ValueError, base64.binascii.Error):
        return f"*** O arquivo que {remetente} mandou veio corrompido. ***"

    if len(dados) > MAX_TAMANHO_ARQUIVO:
        return f"*** Arquivo de {remetente} recusado: passou de {MAX_TAMANHO_ARQUIVO // 1024} KB. ***"

    nome_seguro = os.path.basename(nome) or "arquivo_recebido"
    try:
        os.makedirs(PASTA_RECEBIDOS, exist_ok=True)
        with open(os.path.join(PASTA_RECEBIDOS, nome_seguro), "wb") as arquivo:
            arquivo.write(dados)
    except OSError as erro:
        return f"*** Recebi arquivo de {remetente} mas nao consegui salvar: {erro} ***"

    return f"*** Arquivo '{nome_seguro}' recebido de {remetente} ({len(dados)} bytes), salvo em {PASTA_RECEBIDOS}\\ ***"


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [7] ### - decide a cor de acordo com o tipo da linha
# ------------------------------------------------------------------
def cor_da_linha(linha):
    if "(privado" in linha:
        return COR_PRIVADO
    if linha.startswith(">>>"):
        return COR_ENTROU
    if linha.startswith("<<<"):
        return COR_SAIU
    if linha.startswith("***"):
        return COR_SISTEMA
    return ""    # mensagem normal de chat, sem cor extra


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [2] ### - thread que so fica ouvindo o servidor
# ------------------------------------------------------------------
def receber_mensagens(conexao):
    """
    Roda paralelo ao laco de digitacao. Fica travada no recv() ate
    chegar alguma coisa do servidor, e imprime na tela na hora.
    """
    buffer_texto = ""
    try:
        while not encerrando.is_set():
            dados = conexao.recv(BUFFER)
            if not dados:                       # servidor caiu ou fechou
                print("\n*** Conexao encerrada pelo servidor. ***")
                break

            # Mesmo tratamento de buffer do servidor: so imprime linha inteira
            buffer_texto += dados.decode("utf-8", errors="replace")
            while "\n" in buffer_texto:
                linha, buffer_texto = buffer_texto.split("\n", 1)
                if not linha.strip():
                    continue

                # ### MODIFICACAO DO GRUPO [6] ### - carimbo de data/hora
                # Marca o momento que a mensagem chegou nessa tela, tipo
                # WhatsApp. Cada cliente carimba com o horario local dele.
                carimbo = datetime.now().strftime("%d/%m %H:%M")

                if linha.startswith("@@ARQUIVO@@"):
                    aviso = salvar_arquivo_recebido(linha)
                    print(f"\r{COR_ARQUIVO}[{carimbo}] {aviso}{RESET}\n> ", end="", flush=True)
                    continue

                cor = cor_da_linha(linha)
                # o \r apaga o prompt "> " antes de imprimir a mensagem
                # que chegou, senao o texto recebido fica misturado
                # com o que voce ta digitando
                print(f"\r{cor}[{carimbo}] {linha}{RESET}\n> ", end="", flush=True)

    except OSError:
        if not encerrando.is_set():
            print("\n*** Conexao perdida. ***")
    finally:
        encerrando.set()


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [8] ### - le o arquivo local e manda pro servidor
# ------------------------------------------------------------------
def enviar_arquivo(conexao, texto):
    """
    Trata o comando '/enviararquivo <apelido> <caminho>'. Le o arquivo do
    disco, transforma em base64 (texto puro, sem quebra de linha) e manda
    pro servidor num comando interno '/arquivo', que so repassa os bytes
    pro destinatario certo.
    """
    partes = texto.strip().split(" ", 2)
    if len(partes) < 3:
        print("*** Uso: /enviararquivo <apelido> <caminho_do_arquivo> ***")
        return

    destino, caminho = partes[1], partes[2]
    try:
        with open(caminho, "rb") as arquivo:
            dados = arquivo.read()
    except OSError as erro:
        print(f"*** Nao consegui abrir '{caminho}': {erro} ***")
        return

    if len(dados) > MAX_TAMANHO_ARQUIVO:
        print(f"*** Arquivo grande demais pra essa demo (max {MAX_TAMANHO_ARQUIVO // 1024} KB). ***")
        return

    # "@" e espaco sao separadores do nosso protocolo, entao tira do nome
    nome = os.path.basename(caminho).replace(" ", "_").replace("@", "_")
    conteudo_b64 = base64.b64encode(dados).decode("ascii")

    try:
        conexao.sendall(f"/arquivo {destino} {nome} {conteudo_b64}\n".encode("utf-8"))
    except OSError:
        print("*** Nao consegui enviar: conexao perdida. ***")
        return

    print(f"Enviando '{nome}' ({len(dados)} bytes) para {destino}...")


# ------------------------------------------------------------------
# PROGRAMA PRINCIPAL
# ------------------------------------------------------------------
def main():
    # ### MODIFICACAO DO GRUPO [4] ###
    # Uso: python cliente.py [ip] [porta]
    host = sys.argv[1] if len(sys.argv) > 1 else HOST_PADRAO
    porta = int(sys.argv[2]) if len(sys.argv) > 2 else PORTA_PADRAO

    # socket(AF_INET, SOCK_STREAM) = IPv4 + TCP, igual no exemplo original
    conexao = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    print(f"Conectando em {host}:{porta} ...")
    try:
        conexao.connect((host, porta))
    except OSError as erro:
        print(f"Falha na conexao: {erro}")
        print("Verifica se o servidor ta rodando e se o IP/porta tao certos.")
        return
    print("Conectado!\n")

    # ---- Etapa 1: manda o apelido (o servidor espera isso na 1a linha)
    # ### MODIFICACAO DO GRUPO [3] ###
    try:
        boas_vindas = conexao.recv(BUFFER).decode("utf-8", errors="replace")
        print(boas_vindas.strip())
        apelido = input("Apelido: ").strip() or "Anonimo"
        conexao.sendall((apelido + "\n").encode("utf-8"))
    except (OSError, KeyboardInterrupt):
        conexao.close()
        return

    # ---- Etapa 2: liga a thread que fica recebendo
    thread = threading.Thread(target=receber_mensagens, args=(conexao,), daemon=True)
    thread.start()

    # ---- Etapa 3: laco de digitacao (rodando na thread principal)
    # ### MODIFICACAO DO GRUPO [1] ###
    print("Digite suas mensagens (/ajuda pra ver os comandos, /sair pra sair).\n")
    try:
        while not encerrando.is_set():
            texto = input("> ").strip()
            if not texto:
                continue

            # ### MODIFICACAO DO GRUPO [8] ### - intercepta antes de mandar,
            # porque esse comando precisa ler um arquivo local primeiro
            if texto.lower().startswith("/enviararquivo "):
                enviar_arquivo(conexao, texto)
                continue

            conexao.sendall((texto + "\n").encode("utf-8"))

            if texto.lower() == "/sair":
                break

    except (KeyboardInterrupt, EOFError):
        print("\nEncerrando...")
        try:
            conexao.sendall(b"/sair\n")
        except OSError:
            pass
    except OSError:
        print("\n*** Nao consegui mandar: conexao perdida. ***")
    finally:
        # ### MODIFICACAO DO GRUPO [5] ### - fecha tudo direitinho
        encerrando.set()
        try:
            conexao.shutdown(socket.SHUT_RDWR)
        except OSError:
            pass
        conexao.close()
        print("Cliente finalizado.")


if __name__ == "__main__":
    main()
