"""

Base que a gente usou (material que o professor deu):
"server.c" / "servidor.cpp", na pasta /original. E bem simples: aceita
UM cliente, le UMA mensagem, manda uma frase pronta de volta ("Hello
from server") e encerra o programa. Da pra conversar? Nao da.
Referencia: https://docs.python.org/pt-br/3/howto/sockets.html

O que a gente implementou de novo:
Pegamos essa base e transformamos num chat de verdade, com varios
clientes conectados ao mesmo tempo trocando mensagem. Cada pedaco
novo ta marcado no codigo com "### MODIFICACAO DO GRUPO ###", tipo
assim, resumindo:

[1] Servidor fica escutando pra sempre (nao so uma vez) e abre uma
    THREAD pra cada cliente que entra, entao varias pessoas
    conversam ao mesmo tempo sem uma travar a outra
[2] BROADCAST: mensagem de um cliente vai pra todo mundo, e nao so
    de volta pra quem mandou (que era o que o original original fazia)
[3] Cada cliente escolhe um APELIDO ao entrar, e a sala avisa quando
    alguem entra ou sai
[4] A lista de clientes e compartilhada entre varias threads, entao
    usamos um LOCK pra ninguem mexer nela ao mesmo tempo (senao da
    erro esquisito de condicao de corrida)
[5] Comandos que da pra digitar no chat: /lista /hora /ajuda /sair
[6] Log de tudo que acontece, salvo em servidor_log.txt
[7] Tratamos certinho o buffer das mensagens, porque TCP manda os
    dados em pedacos e nao garante que 1 recv() = 1 mensagem inteira
    (o original assumia isso e dava problema)
-----------------------------------------------------------------------
"""

import socket
import threading
from datetime import datetime

# ------------------------------------------------------------------
# CONFIGURACOES
# ------------------------------------------------------------------
HOST = "0.0.0.0"        # 0.0.0.0 = aceita conexao de qualquer interface de rede
PORTA = 5000             # mesma porta do servidor.cpp original (versao Windows)
MAX_FILA = 10            # quantas conexao pode ficar esperando pra ser aceita
BUFFER = 1024            # bytes lidos por vez no recv
ARQUIVO_LOG = "servidor_log.txt"

# ### MODIFICACAO DO GRUPO [4] ########################################
# Dicionario compartilhado entre TODAS as threads. Como varias threads
# podem mexer nele ao mesmo tempo (um cliente entrando enquanto outro
# sai, por exemplo), a gente protege com um Lock pra nao dar zica.
# clientes = { socket_do_cliente: {"apelido": str, "endereco": (ip, porta)} }
# ######################################################################
clientes = {}
trava = threading.Lock()


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [6] ### - log em arquivo
# ------------------------------------------------------------------
def registrar_log(texto):
    """Escreve o evento no console e no arquivo de log, com data e hora."""
    carimbo = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
    linha = f"[{carimbo}] {texto}"
    print(linha)
    try:
        with open(ARQUIVO_LOG, "a", encoding="utf-8") as arquivo:
            arquivo.write(linha + "\n")
    except OSError as erro:
        print(f"!! Nao consegui gravar no log: {erro}")


# ------------------------------------------------------------------
# Manda uma mensagem pra UM socket so
# ------------------------------------------------------------------
def enviar(conexao, mensagem):
    """
    Manda a mensagem terminada em '\n'.
    sendall() garante que TODOS os bytes saem, diferente do send() do
    exemplo original que pode mandar so um pedaco do buffer as vezes.
    """
    try:
        conexao.sendall((mensagem + "\n").encode("utf-8"))
        return True
    except OSError:
        return False


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [2] ### - manda pra todo mundo (broadcast)
# ------------------------------------------------------------------
def transmitir(mensagem, remetente=None):
    """
    Repassa a mensagem pra todo mundo que ta conectado.
    Se 'remetente' for passado, esse cliente NAO recebe copia da propria
    mensagem (ele ja viu o que digitou, nao precisa mandar de volta).
    """
    with trava:
        destinatarios = list(clientes.keys())

    for conexao in destinatarios:
        if conexao is remetente:
            continue
        if not enviar(conexao, mensagem):
            remover_cliente(conexao)


# ------------------------------------------------------------------
# Tira um cliente da sala com seguranca
# ------------------------------------------------------------------
def remover_cliente(conexao):
    """Tira o cliente da lista, fecha o socket dele e devolve o apelido."""
    with trava:
        dados = clientes.pop(conexao, None)
    try:
        conexao.close()
    except OSError:
        pass
    return dados["apelido"] if dados else None


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [5] ### - comandos que o servidor entende
# ------------------------------------------------------------------
def tratar_comando(conexao, apelido, texto):
    """
    Processa os comandos que comecam com '/'.
    Devolve True se o cliente deve ser desconectado, False se nao.
    """
    comando = texto.strip().lower()

    if comando == "/sair":
        enviar(conexao, "*** Voce saiu da sala. Ate logo! ***")
        return True

    if comando == "/lista":
        with trava:
            nomes = [dados["apelido"] for dados in clientes.values()]
        enviar(conexao, f"*** Conectados ({len(nomes)}): {', '.join(nomes)} ***")
        return False

    if comando == "/hora":
        agora = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        enviar(conexao, f"*** Hora do servidor: {agora} ***")
        return False

    if comando == "/ajuda":
        enviar(conexao, "*** Comandos: /lista  /hora  /ajuda  /sair ***")
        return False

    enviar(conexao, f"*** Comando desconhecido: {texto} (usa /ajuda) ***")
    return False


# ------------------------------------------------------------------
# ### MODIFICACAO DO GRUPO [1] ### - essa funcao roda numa THREAD por cliente
# ------------------------------------------------------------------
def atender_cliente(conexao, endereco):
    """
    Cuida da vida inteira de UM cliente, do inicio ao fim. Como essa
    funcao roda na propria thread dela, varios clientes sao atendidos
    ao mesmo tempo e nenhum fica esperando o outro terminar.
    """
    ip = endereco[0]
    apelido = None
    buffer_texto = ""          # ### MODIFICACAO DO GRUPO [7] ###

    try:
        # ---- Etapa 1: recebe o apelido (primeira linha que o cliente manda)
        enviar(conexao, "Bem-vindo! Informe seu apelido:")
        dados = conexao.recv(BUFFER)
        if not dados:
            return
        apelido = dados.decode("utf-8", errors="replace").strip()
        if not apelido:
            apelido = f"Anonimo_{endereco[1]}"

        # ### MODIFICACAO DO GRUPO [3] ### - nao deixa apelido repetido
        with trava:
            usados = [d["apelido"] for d in clientes.values()]
            base, contador = apelido, 2
            while apelido in usados:
                apelido = f"{base}_{contador}"
                contador += 1
            clientes[conexao] = {"apelido": apelido, "endereco": endereco}
            total = len(clientes)

        registrar_log(f"CONEXAO   : {apelido} entrou ({ip}) - total: {total}")
        enviar(conexao, f"*** Voce entrou como '{apelido}'. Digite /ajuda ***")
        transmitir(f">>> {apelido} entrou na sala.", remetente=conexao)

        # ---- Etapa 2: fica recebendo mensagem
        while True:
            dados = conexao.recv(BUFFER)
            if not dados:                 # cliente fechou a conexao
                break

            # ### MODIFICACAO DO GRUPO [7] #############################
            # TCP e um FLUXO de bytes: um recv() pode trazer meia mensagem
            # ou duas coladas junto. A gente acumula tudo num buffer e so
            # processa linha completa (que termina com '\n'). O exemplo
            # original nao se preocupava com isso.
            # ###########################################################
            buffer_texto += dados.decode("utf-8", errors="replace")
            while "\n" in buffer_texto:
                linha, buffer_texto = buffer_texto.split("\n", 1)
                linha = linha.strip()
                if not linha:
                    continue

                if linha.startswith("/"):
                    if tratar_comando(conexao, apelido, linha):
                        return
                else:
                    registrar_log(f"MENSAGEM  : {apelido} ({ip}): {linha}")
                    transmitir(f"[{apelido}] {linha}", remetente=conexao)

    except ConnectionResetError:
        # No Windows e o erro tipico quando o cliente fecha a janela no X
        registrar_log(f"QUEDA     : conexao com {apelido or ip} caiu")
    except OSError as erro:
        registrar_log(f"ERRO      : {apelido or ip} -> {erro}")
    finally:
        # ---- Etapa 3: limpeza garantida, seja la o que acontecer
        nome = remover_cliente(conexao)
        if nome:
            with trava:
                total = len(clientes)
            registrar_log(f"DESCONEXAO: {nome} saiu ({ip}) - total: {total}")
            transmitir(f"<<< {nome} saiu da sala.")


# ------------------------------------------------------------------
# PROGRAMA PRINCIPAL
# ------------------------------------------------------------------
def main():
    # socket(AF_INET, SOCK_STREAM) = IPv4 + TCP, igual no exemplo original
    servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # SO_REUSEADDR libera a porta na hora depois que fecha, senao da
    # aquele erro chato "Address already in use" quando reinicia o
    # servidor no meio da apresentacao
    servidor.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    try:
        servidor.bind((HOST, PORTA))     # liga o socket no IP e na porta
        servidor.listen(MAX_FILA)        # coloca em modo de escuta
    except OSError as erro:
        print(f"Falha ao iniciar o servidor na porta {PORTA}: {erro}")
        return

    registrar_log(f"SERVIDOR  : escutando em {HOST}:{PORTA}")
    print("Pressione Ctrl+C para encerrar.\n")

    try:
        # ### MODIFICACAO DO GRUPO [1] #################################
        # O original chamava accept() so UMA vez. Aqui o accept() fica
        # num laco infinito e cada conexao aceita ganha a propria thread.
        # daemon=True faz as threads morrerem junto com o programa.
        #
        # No Windows, um accept() bloqueado as vez segura o Ctrl+C ate
        # alguem conectar. Por isso botamos um timeout: a cada 1s sem
        # conexao nova, da timeout, o laco volta pro topo e o Python
        # consegue entregar o Ctrl+C direito.
        # ################################################################
        servidor.settimeout(1.0)
        while True:
            try:
                conexao, endereco = servidor.accept()
            except socket.timeout:
                continue
            thread = threading.Thread(
                target=atender_cliente,
                args=(conexao, endereco),
                daemon=True,
            )
            thread.start()

    except KeyboardInterrupt:
        registrar_log("SERVIDOR  : encerrado pelo operador (Ctrl+C)")
        transmitir("*** O servidor foi encerrado. ***")
        with trava:
            conexoes = list(clientes.keys())
        for conexao in conexoes:
            remover_cliente(conexao)
    finally:
        servidor.close()


if __name__ == "__main__":
    main()
