#include <WINSOCK2.H>
#include <STDIO.H>
#pragma comment(lib,"WS2_32.lib")

int main(int argc, char* argv[])
{
	WORD wVersionRequested; //Winsock libray version
	WSADATA wsaData; //
	int err;
	
	wVersionRequested=MAKEWORD(1,1);
	
	err=WSAStartup(wVersionRequested, &wsaData);
	if (err!=0)
	{
		return -1;
	}
	
	if (LOBYTE(wsaData.wVersion)!=1||
		HIBYTE(wsaData.wVersion)!=1)
	{
		//not requested version, exit
		WSACleanup();
		return -1;
	}
	
	//create socket
	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
	
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);
	
	connect(sockClient, (SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	
	char recvBuf[100];
	recv(sockClient,recvBuf,100,0);
	printf("%s\n",recvBuf);
	
	const char sendBuf[100]= "Connected\0";
	send(sockClient,sendBuf,strlen(sendBuf)+1,0);
	
	closesocket(sockClient);
	WSACleanup();
	
	return 0;
	
	
}