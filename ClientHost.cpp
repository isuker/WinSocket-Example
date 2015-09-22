//
// Created by Jianhui Zhu on 15-09-17.
//

#include "ClientHost.h"
ClientHost::ClientHost(SOCKET mySocket, SOCKADDR_IN sockaddrIn) {
    int errorMessage=0;
    clientSocket=mySocket;
	errorMessage = bind(mySocket, (struct sockaddr*)&sockaddrIn, sizeof(sockaddrIn));
    if(errorMessage<0){

    }
}
ClientHost ClientHost::connectServer(SOCKADDR_IN server) {
	int rlt = 0;
	int iErrMsg;
	WSAData wsaData;
	iErrMsg = WSAStartup(MAKEWORD(1, 1), &wsaData);
	if (iErrMsg != NO_ERROR){
		printf("failed with wsaStartup error : %d\n", iErrMsg);
		throw 1;
	}
	if (clientSocket == INVALID_SOCKET){
		printf("socket failed with error : %d\n", WSAGetLastError());
		throw 2;
	}
	iErrMsg = connect(clientSocket,(sockaddr*)&server, sizeof(server));
	if (iErrMsg < 0)
	{
		printf("connect failed with error : %d\n", iErrMsg);
		throw 3;
	}
	return *this;
}
ClientHost ClientHost::sendMessage(const char* msg) {
	int rlt = 0;
	int iErrMsg = 0;

	iErrMsg = send(clientSocket, msg, strlen(msg), 0);
	if (iErrMsg < 0)
	{
		printf("send msg failed with error : %d\n", iErrMsg);
		throw 1;
	}
	return *this;
}