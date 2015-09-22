//
// Created by Jianhui Zhu on 15-09-17.
//

#ifndef HOSTFORSOCKET_HOSTBUILDER_H
#define HOSTFORSOCKET_HOSTBUILDER_H
#pragma comment(lib, "Ws2_32.lib")
#include "ServerHost.h"
#include "ClientHost.h"
#include <winsock.h>
#include "WinSocketBuilder.h"
class HostBuilder {
    private:
    SOCKADDR_IN socketAddress;
    SOCKET mySocket;
    public:
        static HostBuilder newInstance();
        ServerHost buildServer();
        ClientHost buildClient();
        HostBuilder setAddressFamilyIPv4();
        HostBuilder setAddressFamilyIPXSPX();
        HostBuilder setAddressFamilyAppleTalk();
        HostBuilder setAddressFamilyNetBIOS();
        HostBuilder setAddressFamilyIPv6();
        HostBuilder setAddressFamilyIrDA();
        HostBuilder setAddressFamilyBluetooth();
        HostBuilder setPortNumber(int);
        HostBuilder setAddress(const char*);
};


#endif //HOSTFORSOCKET_HOSTBUILDER_H
