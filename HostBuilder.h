//
// Created by Jianhui Zhu on 15-09-17.
//

#ifndef HOSTFORSOCKET_HOSTBUILDER_H
#define HOSTFORSOCKET_HOSTBUILDER_H


class HostBuilder {
    private:
    SOCKADDR_IN socketAddress;
    SOCKET mySocket;
    public:
        static HostBuilder newInstance();
        ServerHost buildServer();
        ClientHost buildClient();
        HostBuilder setAddressFamily(int);
        HostBuilder setPortNumber(int);
        HostBuilder setAddress(const char*);
};


#endif //HOSTFORSOCKET_HOSTBUILDER_H
