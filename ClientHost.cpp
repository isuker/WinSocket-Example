//
// Created by Jianhui Zhu on 15-09-17.
//

#include "ClientHost.h"
ClientHost::ClientHost(SOCKET mySocket, SOCKADDR_IN sockaddrIn) {
    int errorMessage;
    this->clientSocket=mySocket;
    errorMessage = bind(mySocket,&sockaddrIn,sizeof(sockaddrIn));
    if(errorMessage<0){

    }
}
ClientHost ClientHost::connect() {

}
ClientHost ClientHost::sendMessage() {

}