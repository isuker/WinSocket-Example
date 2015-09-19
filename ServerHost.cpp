//
// Created by Jianhui Zhu on 15-09-17.
//

#include "ServerHost.h"
ServerHost::ServerHost(SOCKET mySocket, SOCKADDR_IN sockaddrIn) {
    int errorMessage;
    serverSocket=mySocket;
	server = sockaddrIn;
    errorMessage = bind(mySocket,(struct sockaddr*)&sockaddrIn,sizeof(sockaddrIn));
    if(errorMessage<0){
		closesocket(mySocket);
		throw errorMessage;
    }
}
SOCKADDR_IN ServerHost::getServerSocketAddress(){
	return server;
}
void ServerHost::listenRequest() {
	listen(serverSocket, 5);
	sockaddr_in tcpAddr;
	int len = sizeof(sockaddr);
	SOCKET newSocket;
	char buf[1024];
	int rval;
	do
	{
		newSocket = accept(serverSocket, (sockaddr*)&tcpAddr, &len);
		if (newSocket == INVALID_SOCKET){
			std::cout << "Invalid socket";
		}else{
			printf("new socket connect : %d\n", newSocket);
			do{
				printf("process\n");
				memset(buf, 0, sizeof(buf));
				rval = recv(newSocket, buf, 1024, 0);
				if (rval == SOCKET_ERROR)
					printf("recv socket error\n");
				if (rval == 0)
					printf("ending connection");
				else
					printf("recv %s\n", buf);
			} while (rval != 0);
			closesocket(newSocket);
		}
	} while (1);
	closesocket(serverSocket);
}