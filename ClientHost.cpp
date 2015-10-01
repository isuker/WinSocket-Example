//
// Created by Jianhui Zhu on 15-09-17.
//
#include "LogFileWriter.h"
#include <fstream>
#include <time.h> 
#include "ClientHost.h"
ClientHost::ClientHost(SOCKET mySocket, SOCKADDR_IN sockaddrIn,std::ofstream* file) {
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
	iErrMsg = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iErrMsg != NO_ERROR){
		printf("failed with wsaStartup error : %d\n", iErrMsg);
		throw 1;
	}
	if (clientSocket == INVALID_SOCKET){
		printf("socket failed with error : %d\n", WSAGetLastError());
		throw 2;
	}
	int timeCounter = 1;
	char buf [1024];
	int serverLength = sizeof(server);
	
	for (; timeCounter <= 3; timeCounter++){
		sprintf_s(buf, "Client: %d client call\n", timeCounter);
		//LogFileWriter::getInstance()->writeLine(buf);
		if (sendto(clientSocket, buf, sizeof(buf), 0, (SOCKADDR*)&server, serverLength) != SOCKET_ERROR){
			std::cout << buf;
			//LogFileWriter::getInstance()->writeLine(buf);
			if (recvfrom(clientSocket, buf, sizeof(buf), 0, (SOCKADDR*)&server, &serverLength) != SOCKET_ERROR){
				std::cout << "Client: received server " << buf[8] << " response\n";
				//LogFileWriter::getInstance()->writeLine(buf);
			}
		}
	}
	if (timeCounter == 4){
		std::cout << "Successfully connected\n";
		//LogFileWriter::getInstance()->writeLine(buf);
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