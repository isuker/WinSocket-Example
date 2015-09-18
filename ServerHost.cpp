//
// Created by Jianhui Zhu on 15-09-17.
//

#include "ServerHost.h"
ServerHost::ServerHost(SOCKET mySocket, SOCKADDR_IN sockaddrIn) {
    int errorMessage;
    this->serverSocket=mySocket;
    errorMessage = bind(mySocket,&sockaddrIn,sizeof(sockaddrIn));
    if(errorMessage<0){

    }
}

void ServerHost::listenRequest() {
    
}