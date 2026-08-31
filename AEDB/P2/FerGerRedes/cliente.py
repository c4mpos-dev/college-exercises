"""
-----------------------------------------------------------------------
CLIENTE DE CHAT VIA SOCKET TCP
-----------------------------------------------------------------------
Trabalho de Redes de Computadores
Grupo   : [PREENCHER COM OS NOMES DO GRUPO]
Data    : [PREENCHER]

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
-----------------------------------------------------------------------
"""

import socket
import sys
import threading
from datetime import datetime

# ------------------------------------------------------------------
# CONFIGURACOES PADRAO (da pra trocar passando argumento na linha de comando)
# ------------------------------------------------------------------
HOST_PADRAO = "127.0.0.1"   # 127.0.0.1 = a propria maquina (localhost)
PORTA_PADRAO = 5000
BUFFER = 1024

# Avisa pra thread que fica recebendo que o programa ta terminando
encerrando = threading.Event()


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
                if linha.strip():
                    # ### MODIFICACAO DO GRUPO [6] ### - carimbo de data/hora
                    # Marca o momento que a mensagem chegou nessa tela, tipo
                    # WhatsApp. Cada cliente carimba com o horario local dele.
                    carimbo = datetime.now().strftime("%d/%m %H:%M")
                    # o \r apaga o prompt "> " antes de imprimir a mensagem
                    # que chegou, senao o texto recebido fica misturado
                    # com o que voce ta digitando
                    print(f"\r[{carimbo}] {linha}\n> ", end="", flush=True)

    except OSError:
        if not encerrando.is_set():
            print("\n*** Conexao perdida. ***")
    finally:
        encerrando.set()


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
