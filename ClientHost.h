//
// Created by Jianhui Zhu on 15-09-17.
//

#ifndef HOSTFORSOCKET_CLIENTHOST_H
#define HOSTFORSOCKET_CLIENTHOST_H
#include <winsock.h>
#include <iostream>
class HostBuilder;

class ClientHost {
	friend class HostBuilder;
    private:
        SOCKET clientSocket;
        ClientHost(SOCKET,SOCKADDR_IN) throw (int);
    
    public:
		ClientHost connectServer(SOCKADDR_IN) throw (int);
		ClientHost sendMessage(const char* msg) throw (int);
	
};

#endif //HOSTFORSOCKET_CLIENTHOST_H

