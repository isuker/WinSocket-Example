//
// Created by Jianhui Zhu on 15-09-17.
//

#ifndef HOSTFORSOCKET_CLIENTHOST_H
#define HOSTFORSOCKET_CLIENTHOST_H


class ClientHost {
    private:
        SOCKET clientSocket;
        ClientHost(SOCKET,SOCKADDR_IN);
    friend ClientHost HostBuilder::buildClient();
    public:
        ClientHost connect();
        ClientHost sendMessage();
};


#endif //HOSTFORSOCKET_CLIENTHOST_H
