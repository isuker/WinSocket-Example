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
		mySocket = WinSocketBuilder::newInstance().setAddressFamily(socketAddress.sin_family)
			.build();
		return ServerHost(mySocket,socketAddress);
    }

	ClientHost HostBuilder::buildClient(){
		mySocket = WinSocketBuilder::newInstance().setAddressFamily(socketAddress.sin_family)
			.build();
		return ClientHost(mySocket, socketAddress);
	}