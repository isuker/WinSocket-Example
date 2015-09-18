//
// Created by Jianhui Zhu on 15-09-17.
//

#include "HostBuilder.h"
    HostBuilder HostBuilder::newInstance() {
        return HostBuilder();
    }

    HostBuilder HostBuilder::setAddress(const char * address) {
        socketAddress.sin_addr.s_addr = inet_addr(address);
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamily(int addressFamily) {
        socketAddress.sin_family = addressFamily;
        return *this;
    }
    HostBuilder HostBuilder::setPortNumber(int portNumber) {
        socketAddress.sin_port=portNumber;
        return *this;
    }
    ServerHost HostBuilder::buildServer() {
        return ServerHost::newInstance(mySocket,socketAddress);
    }