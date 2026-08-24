// Programa servidor: servidor.cpp

#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE "Eu sou o servidor!\n"
#define PORTA   5000

main()
{
   WSADATA wsda;
   char Mensagem[80];               
   char BufferEnt[128];
   char Servidor[256];
   int  ret, TamBuffer, TamEndereco, TamMensagem;                            
   SOCKET sEscuta, sCliente;            
   SOCKADDR_IN EnderLocal, EnderRemoto;     
   struct hostent *hp;
   
   WSAStartup(MAKEWORD(1,1), &wsda);

   printf("Criando socket\n");
   sEscuta = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if (sEscuta == SOCKET_ERROR)
   {
      printf("Erro na criacao do sock: %d\n", WSAGetLastError());
      exit(1);
   }

   gethostname(Servidor, sizeof(Servidor));
   hp = gethostbyname(Servidor);
   if(hp == NULL)
   {
      printf("Erro em obter o nome do servidor: %d\n", WSAGetLastError());
      exit(1);
   }

   EnderLocal.sin_family = hp->h_addrtype;
   EnderLocal.sin_port = PORTA;
   memcpy((char *)&EnderLocal.sin_addr,hp->h_addr, hp->h_length);

   printf("Binding socket ao endereco %s na porta %d\n", inet_ntoa(EnderLocal.sin_addr), EnderLocal.sin_port);
   ret = bind(sEscuta, (struct sockaddr *) &EnderLocal, sizeof(EnderLocal));
   if(ret == SOCKET_ERROR)
   {
      printf("Error no bind: %d\n", WSAGetLastError());
      exit(1);
   }

   printf("Colocando o socket no modo de escuta\n");
   ret = listen(sEscuta, 10);
   if(ret == SOCKET_ERROR)
   {
      printf("Error na chamada do listen: %d\n", WSAGetLastError());
      exit(1);
   }

   printf("Aguardando por conexoes (tecle Ctrl-C para sair)...\n");
   TamEndereco = sizeof(EnderRemoto);
   sCliente = accept(sEscuta, (struct sockaddr *) &EnderRemoto, &TamEndereco);
   if(sCliente == SOCKET_ERROR)
   {
      printf("Erro no accept: %d\n", WSAGetLastError());
      exit(1);
   }

   printf("Cliente %s conectado\n", inet_ntoa(EnderRemoto.sin_addr));

   printf("Recebendo mensagem\n");
   ret = recv(sCliente, BufferEnt, sizeof(BufferEnt), 0);
   if(ret == SOCKET_ERROR)
   {
      printf("Erro no receive: %d\n", WSAGetLastError());
      exit(1);
   }
   TamBuffer = ret;		
   BufferEnt[TamBuffer] = '\0';	
   printf("Dado recebido: %s", BufferEnt);

   printf("Enviando mensagem\n");
   strcpy(Mensagem, MESSAGE);
   TamMensagem = strlen(Mensagem);
   ret = send(sCliente, Mensagem, TamMensagem, 0);
   if(ret == SOCKET_ERROR)
   {
      printf("Erro no envio: %d\n", WSAGetLastError());
      exit(1);
   }

   closesocket(sCliente);
   closesocket(sEscuta);
   WSACleanup();
   exit(0);
}