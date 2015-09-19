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
ClientHost ClientHost::sendMessage(const char* msg, int len) {
	int rlt = 0;

	int iErrMsg = 0;

	//发送消息，指定sock发送消息
	iErrMsg = send(clientSocket, msg, len, 0);
	if (iErrMsg < 0)
		//发送失败
	{
		printf("send msg failed with error : %d\n", iErrMsg);
		throw 1;
	}
	return *this;
}