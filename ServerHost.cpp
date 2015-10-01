//
// Created by Jianhui Zhu on 15-09-17.
//
#include<fstream>
#include <time.h> 
#include "LogFileWriter.h"
#include "ServerHost.h"
ServerHost::ServerHost(SOCKET mySocket, SOCKADDR_IN sockaddrIn,std::ofstream* file) {
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
		int timeCounter = 1;
		char buf[1024];
		int serverLength = sizeof(server);

		for (int retryCounter = 0; timeCounter <= 3&&retryCounter<1000; timeCounter++){
			
				if (recvfrom(serverSocket, buf, sizeof(buf), 0, (SOCKADDR*)&server, &serverLength) != SOCKET_ERROR){
					std::cout << "Server: received client "<<buf[8]<<" call\n";
					//LogFileWriter::getInstance()->writeLine(buf);
					sprintf_s(buf, "Server: %d response to client\n",timeCounter);
					if (sendto(serverSocket, buf, sizeof(buf), 0, (SOCKADDR*)&server, serverLength) != SOCKET_ERROR){
						std::cout << buf;
						//LogFileWriter::getInstance()->writeLine(buf);
					}
					else{
						timeCounter = 1;
						retryCounter++;
						continue;
					}
				}
				else{
					timeCounter = 1;
					retryCounter++;
					continue;
				}
		}
	
}