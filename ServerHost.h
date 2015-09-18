//
// Created by Jianhui Zhu on 15-09-17.
//

#ifndef HOSTFORSOCKET_SERVERHOST_H
#define HOSTFORSOCKET_SERVERHOST_H


class ServerHost {
    private:
        SOCKET serverSocket;
        ServerHost(SOCKET,SOCKADDR_IN);
    friend ServerHost HostBuilder::buildServer();
    public:
        void listenRequest();
};


#endif //HOSTFORSOCKET_SERVERHOST_H
