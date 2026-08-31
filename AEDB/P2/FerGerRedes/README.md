# Chat Multi-Cliente com Sockets TCP (Python)

Trabalho de Redes de Computadores — Interface de Programação de Rede (Socket)

**Grupo:** [preencher]
**Data:** [preencher]

> Este arquivo existe pra quem está entrando no grupo agora conseguir entender o projeto rápido, sem precisar ler todo o código primeiro.

---

## 1. O que é o projeto, em uma frase

Uma sala de bate-papo em rede, no terminal. Um **servidor** aceita vários **clientes** ao mesmo tempo e retransmite (broadcast) cada mensagem recebida para todos os demais participantes — como um grupo de WhatsApp bem simples, feito na mão com Python e sockets TCP.

## 2. Onde as coisas estão

```
AEDB/P2/FerGerRedes/
├── servidor.py        # servidor concorrente, uma thread por cliente
├── cliente.py          # cliente com thread de recepção
├── README.md            # este arquivo
├── gerar_exe.bat        # gera os .exe com PyInstaller
└── original/            # programas-base em C/C++ fornecidos pelo professor
    ├── server.c, client.c        (versão Linux)
    └── server.cpp, client.cpp    (versão Windows/Winsock)
```

`servidor_log.txt` também aparece na pasta depois que o servidor roda pela primeira vez — é gerado automaticamente, não faz parte do código-fonte.

## 3. Como executar (Windows)

Requer Python 3.8 ou superior. Abra **três ou mais** janelas do Prompt de Comando (ou PowerShell) na pasta `AEDB/P2/FerGerRedes`.

Na primeira janela (servidor):
```
python servidor.py
```

Nas demais (um cliente por janela):
```
python cliente.py
```
Cada cliente vai pedir um apelido antes de entrar na sala.

Para conectar de **outro computador** na mesma rede, descubra o IP do servidor com `ipconfig` e use:
```
python cliente.py 192.168.0.10 5000
```

Se o Firewall do Windows perguntar, autorize o acesso em **Redes privadas**.

## 4. Comandos disponíveis no chat

| Comando | Efeito |
|---|---|
| `/ajuda` | Lista os comandos |
| `/lista` | Mostra quem está conectado |
| `/hora` | Mostra a hora do servidor |
| `/privado <apelido> <mensagem>` | Manda mensagem só pra um usuário, sem o resto da sala ver |
| `/sair` | Sai da sala |

## 5. O que foi modificado em relação ao programa original

O programa original (pasta `original/`) aceita **um** cliente, lê **uma** mensagem, responde uma frase fixa e encerra. Todas as alterações do grupo estão marcadas no código com o comentário `### MODIFICACAO DO GRUPO [n] ###`, então dá pra achar cada uma direto no `servidor.py`/`cliente.py` pelo número.

| # | Original | Nossa versão |
|---|---|---|
| 1 | `accept()` chamado uma única vez | Laço infinito de `accept()` + uma **thread** por cliente |
| 2 | Responde só a quem enviou | **Broadcast**: retransmite para todos os outros |
| 3 | Clientes anônimos | **Apelido** por cliente, com aviso de entrada/saída e resolução de nomes repetidos (`Nome_2`, `Nome_3`...) |
| 4 | Sem estado compartilhado | Lista de clientes protegida por **Lock** (exclusão mútua) |
| 5 | Frase fixa `"Hello from server"` | **Comandos** `/lista`, `/hora`, `/ajuda`, `/sair` |
| 6 | Sem registro | **Log** em arquivo com data, hora e IP |
| 7 | Assume que 1 `recv()` = 1 mensagem | **Buffer** com delimitador `\n`, tratando TCP como fluxo de bytes |
| 8 | Cliente sequencial (envia → espera) | Cliente com **thread receptora** paralela ao teclado |
| 9 | Mensagens sem hora nenhuma | **Timestamp** (data + horário) em toda mensagem que chega na tela |
| 10 | Sem forma de falar só com uma pessoa | Comando **`/privado`** pra mandar mensagem direto pra um usuário |

Além disso, o servidor tem um pequeno ajuste de robustez: no Windows, um `accept()` bloqueado pode "segurar" o Ctrl+C até alguém conectar. Por isso o servidor usa um timeout de 1s no socket de escuta, pra sempre conseguir encerrar rápido com Ctrl+C (isso está marcado dentro da modificação `[1]`, no `main()` do `servidor.py`).

Os itens 9 e 10 são as modificações mais recentes: `[6]` no `cliente.py` (timestamp) e `[8]` no `servidor.py` (`/privado`) — os números entre parênteses são os que aparecem nos comentários `### MODIFICACAO DO GRUPO ###` dentro de cada arquivo (a numeração reinicia em cada arquivo).

## 6. Conceitos de rede demonstrados

- **Socket**: ponto final de comunicação identificado por IP + porta (pense num prédio: IP é o endereço, porta é o número do apartamento).
- **TCP (`SOCK_STREAM`)**: orientado a conexão, confiável, entrega ordenada — por isso é adequado para chat.
- **Fluxo do servidor**: `socket()` → `bind()` → `listen()` → `accept()` → `recv()`/`sendall()` → `close()`.
- **Fluxo do cliente**: `socket()` → `connect()` → `sendall()`/`recv()` → `close()`.
- **`SO_REUSEADDR`**: libera a porta imediatamente após o encerramento.
- **Concorrência**: uma thread bloqueada em `recv()` não impede as outras de trabalhar.

## 7. Status atual do trabalho (o que já foi feito e o que falta)

- [x] Código funcionando: servidor + múltiplos clientes testados, broadcast, comandos e log verificados.
- [ ] Preencher identificação (nomes do grupo e data) no cabeçalho de `servidor.py`, `cliente.py` e deste arquivo.
- [ ] Gerar os binários `.exe` com `gerar_exe.bat` e testar se eles abrem.
- [ ] Montar a apresentação em PDF (com as referências abaixo incluídas).
- [ ] Empacotar tudo num `.zip` final (fonte + `original/` + `dist/` com os `.exe`, sem `__pycache__`, `build/` nem `servidor_log.txt`).

## 8. Armadilhas conhecidas

- **Firewall do Windows** pede autorização na primeira execução do servidor — marcar "Redes privadas".
- **Rede da faculdade** costuma isolar clientes no Wi-Fi, impedindo um notebook de ver o outro. Plano B: rodar servidor e clientes na mesma máquina, em janelas diferentes.
- **Porta 5000 ocupada** por outro processo: mudar a constante `PORTA` nos dois arquivos.

## 9. Referências

Estas precisam aparecer no slide final da apresentação em PDF:

- Documentação oficial Python — HOWTO de programação com sockets (pt-BR): https://docs.python.org/pt-br/3/howto/sockets.html
- Documentação oficial Python — módulo `socket`: https://docs.python.org/3/library/socket.html
- Documentação oficial Python — módulo `threading`: https://docs.python.org/pt-br/3/library/threading.html
- RFC 793 — Transmission Control Protocol: https://www.rfc-editor.org/rfc/rfc793
- Beej's Guide to Network Programming: https://beej.us/guide/bgnet/
- PyInstaller — geração de executáveis: https://pyinstaller.org/en/stable/

> Acrescente aqui qualquer outro link que o grupo consultar durante o trabalho.
