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
    HostBuilder HostBuilder::setAddressFamilyIPv4(){
        socketAddress.sin_family=2;
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamilyIPXSPX(){
        socketAddress.sin_family=6;
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamilyAppleTalk(){
        socketAddress.sin_family=16;
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamilyNetBIOS(){
        socketAddress.sin_family=17;
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamilyIPv6(){
        socketAddress.sin_family=23;
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamilyIrDA(){
        socketAddress.sin_family=26;
        return *this;
    }
    HostBuilder HostBuilder::setAddressFamilyBluetooth(){
        socketAddress.sin_family=32;
        return *this;
    }