#include <WINSOCK2.H>
#include <STDIO.H>
#pragma comment(lib,"WS2_32.lib")

void main(int argc, char* argv[])
{
	
	WORD wVersionRequested; //Winsock libray version
	WSADATA wsaData; //
	int err;
	
	wVersionRequested=MAKEWORD(1,1);
	
	err=WSAStartup(wVersionRequested, &wsaData);
	if (err!=0)
	{
		return;
	}
	
	if (LOBYTE(wsaData.wVersion)!=1||
		HIBYTE(wsaData.wVersion)!=1)
	{
		//not requested version, exit
		WSACleanup();
		return;
	}
	
	//create socket
	//use TCP/IP, stream socket, automaticly select protocol
	SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);
	printf("Create socket...\n");
	
	//bind socket, and listen
	bind(sockSrv,(SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	listen(sockSrv,5);
	printf("Bind socket and start listenning...\n");
	
	SOCKADDR_IN addrClient;
	int len=sizeof(SOCKADDR);
	
	while(1)
	{
		//wait untill request come
		SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
		printf("Accept request...\n");
		char sendBuf[100];
		sprintf(sendBuf,"Weclome %s to the console server...",
			inet_ntoa(addrClient.sin_addr));
		//send message
		send(sockConn,sendBuf,strlen(sendBuf)+1,0);
		printf("Send out message...\n");
		char recvBuf[100];
		recv(sockConn,recvBuf,100,0);
		printf("%s\n",recvBuf);
		closesocket(sockConn);
		printf("Close socket...\n");
	}
	
	
	return;
	
}