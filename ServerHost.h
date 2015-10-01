//
// Created by Jianhui Zhu on 15-09-17.
//

#ifndef HOSTFORSOCKET_SERVERHOST_H
#define HOSTFORSOCKET_SERVERHOST_H
#include <winsock.h>
#include <iostream>
class HostBuilder;
class ServerHost {
	friend class HostBuilder;
    private:
        SOCKET serverSocket;
		SOCKADDR_IN server;
		ServerHost(SOCKET, SOCKADDR_IN,std::ofstream*) throw (int);
    public:
        void listenRequest();
		SOCKADDR_IN getServerSocketAddress();
		
};


#endif //HOSTFORSOCKET_SERVERHOST_H
