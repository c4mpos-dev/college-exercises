// Programa cliente: cliente.cpp

#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE	"Eu sou o cliente!\n"
#define PORTA   5000

int main(int argc, int **argv)
{
   WSADATA wsda;
   struct hostent *hp;
   char Mensagem[80];
   char BufferEnt[128];
   char Servidor[256];
   int TamBuffer, TamMensagem, ret;
   SOCKET sCliente;		
   SOCKADDR_IN EnderRemoto;	

   WSAStartup(MAKEWORD(1,1), &wsda);

   if(argc != 2) 
      gethostname(Servidor, sizeof(Servidor));
   else
      strcpy(Servidor, (char *) &argv[1][0]);

   hp = gethostbyname(Servidor);
   if(hp == NULL)
   {
      printf("Erro em obter o nome do servidor: %d\n", WSAGetLastError());
      exit(1);
   }	
   EnderRemoto.sin_family = hp->h_addrtype;     
   EnderRemoto.sin_port = PORTA;
   memcpy((char *)&EnderRemoto.sin_addr, hp->h_addr, hp->h_length);

   printf("Criando o socket\n");
   sCliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(sCliente == SOCKET_ERROR)
   {
      printf("Erro na criacao do socket: %d\n", WSAGetLastError());
      exit(1);
   }   
   
   printf("Conectando no servidor %s porta %d\n",inet_ntoa(EnderRemoto.sin_addr),PORTA);
   ret = connect(sCliente,(struct sockaddr *) &EnderRemoto,sizeof(EnderRemoto));
   if(ret == SOCKET_ERROR)
   {
      printf("Erro na conexao com o servidor: %d\n", WSAGetLastError());
      exit(1);
   }

   printf("Enviando mensagem\n");
   strcpy(Mensagem, MESSAGE);
   TamMensagem = strlen(Mensagem);
   ret = send(sCliente, Mensagem, TamMensagem, 0);
   if(ret == SOCKET_ERROR)
   {
      printf("Erro no envio da mensagem: %d\n", WSAGetLastError());
      exit(1);
   }

   printf("Aguardando resposta\n");
   ret = recv(sCliente, BufferEnt, sizeof(BufferEnt), 0);
   if(ret == SOCKET_ERROR)
   {
      printf("Erro no receive: %d\n", WSAGetLastError());
      exit(1);
   }

   TamBuffer = ret;
   BufferEnt[TamBuffer] = '\0';
   printf("Resposta recebida: %s\n", BufferEnt);

   closesocket(sCliente);
   WSACleanup();
   exit(0);
}