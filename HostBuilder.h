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
    int protocolType = 6;
    int socketType = 1;
    SOCKET mySocket;
    public:
        static HostBuilder newInstance();
        ServerHost buildServer();
        ClientHost buildClient();
        /*
         AF_INET   : 2
         The Internet Protocol version 4 (IPv4) address family.
         */
        HostBuilder setAddressFamilyIPv4();
        /*
         * AF_IPX	  : 6
		   The IPX/SPX address family. This address family is only supported if the NWLink IPX/SPX NetBIOS Compatible Transport protocol is installed.
		   This address family is not supported on Windows Vista and later.
         */
        HostBuilder setAddressFamilyIPXSPX();
        /*
         * AF_APPLETALK  : 16
			The AppleTalk address family. This address family is only supported if the AppleTalk protocol is installed.
			This address family is not supported on Windows Vista and later.
         */
        HostBuilder setAddressFamilyAppleTalk();
        /*
         * AF_NETBIOS    : 17
					The NetBIOS address family.
					This address family is only supported if the Windows Sockets provider for NetBIOS is installed.
					The Windows Sockets provider for NetBIOS is supported on 32-bit versions of Windows.
					This provider is installed by default on 32-bit versions of Windows.
					The Windows Sockets provider for NetBIOS is not supported on 64-bit versions of windows
					including Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP.
					The Windows Sockets provider for NetBIOS only supports sockets where the type parameter is set to SOCK_DGRAM.
					The Windows Sockets provider for NetBIOS is not directly related to the NetBIOS programming interface.
					The NetBIOS programming interface is not supported on Windows Vista, Windows Server 2008, and later.
         */
        HostBuilder setAddressFamilyNetBIOS();
        /*
         * AF_INET6 : 23
			The Internet Protocol version 6 (IPv6) address family.
         */
        HostBuilder setAddressFamilyIPv6();
        /*
         * AF_IRDA : 26
			The Infrared Data Association (IrDA) address family.
			This address family is only supported if the computer has an infrared port and driver installed.
         */
        HostBuilder setAddressFamilyIrDA();
        /*
         * AF_BTH : 32
			The Bluetooth address family.
			This address family is supported on Windows XP with SP2 or later if the computer has a Bluetooth adapter and driver installed.
         */
        HostBuilder setAddressFamilyBluetooth();
        /*
         * set the port number for the socket
         * Parameters # of port
         */
        HostBuilder setPortNumber(int);
        /*
         * set the port number randomly
         */
        HostBuilder setPortNumberRandom();
        /*
         * IPPROTO_TCP : 6
     	 	 The Transmission Control Protocol (TCP).
     	 	 This is a possible value when the af parameter is AF_INET or AF_INET6 and the type parameter is SOCK_STREAM.
         */
        HostBuilder setProtocolTCP();
        /*
         * IPPROTO_UDP : 17
     	 	 The User Datagram Protocol (UDP).
     	 	 This is a possible value when the af parameter is AF_INET or AF_INET6 and the type parameter is SOCK_DGRAM.
         */
        HostBuilder setProtocolUDP();
        /*
         * IPPROTO_ICMP : 1
     	 	 The Internet Control Message Protocol (ICMP).
     	 	 This is a possible value when the af parameter is AF_UNSPEC, AF_INET,
     	 	 or AF_INET6 and the type parameter is SOCK_RAW or unspecified.
         */
        HostBuilder setProtocolICMP();
        /*
         * IPPROTO_IGMP : 2
     	 	 The Internet Group Management Protocol (IGMP).
     	 	 This is a possible value when the af parameter is AF_UNSPEC, AF_INET,
     	 	 or AF_INET6 and the type parameter is SOCK_RAW or unspecified.
         */
        HostBuilder setProtocolIGMP();
        /*
         * Bluetooth RFCOMM : 3
     	 	 The Bluetooth Radio Frequency Communications (Bluetooth RFCOMM) protocol.
     	 	 This is a possible value when the af parameter is AF_BTH and the type parameter is SOCK_STREAM.
     	 	 This protocol value is supported on Windows XP with SP2 or later.
         */
        HostBuilder setProtocolBluetoothRFCOMM();
        /*
         * IPPROTO_ICMPV6 : 58
     	 	 The Internet Control Message Protocol Version 6 (ICMPv6).
     	 	 This is a possible value when the af parameter is AF_UNSPEC, AF_INET, or AF_INET6 and the type parameter is SOCK_RAW or unspecified.
     	 	 This protocol value is supported on Windows XP and later.
         */
        HostBuilder setProtocolICMPv6();
        /*
         * IPPROTO_RM : 113
     	 	 The PGM protocol for reliable multicast.
     	 	 This is a possible value when the af parameter is AF_INET and the type parameter is SOCK_RDM.
     	 	 On the Windows SDK released for Windows Vista and later, this protocol is also called IPPROTO_PGM.
     	 	 This protocol value is only supported if the Reliable Multicast Protocol is installed.
         */
        HostBuilder setProtocolRM();
        /*
         * set the address for the host.
         * If not given, by default is localhost: 127.0.0.1
         */
        HostBuilder setAddress(const char*);
        /*
         * SOCK_STREAM : 1
     	 	 A socket type that provides sequenced, reliable, two-way,
     	 	 connection-based byte streams with an OOB data transmission mechanism.
     	 	 This socket type uses the Transmission Control Protocol (TCP)
     	 	 for the Internet address family (AF_INET or AF_INET6).
         */
        HostBuilder setSocketTypeSTREAM();
        /*
         * SOCK_DGRAM : 2
     	 	 A socket type that supports datagrams, which are connectionless,
     	 	 unreliable buffers of a fixed (typically small) maximum length.
     	 	 This socket type uses the User Datagram Protocol (UDP)
     	 	 for the Internet address family (AF_INET or AF_INET6).
         */
        HostBuilder setSocketTypeDGRAM();
        /*
         * SOCK_RAW : 3
     	 	 A socket type that provides a raw socket that
     	 	 allows an application to manipulate the next upper-layer protocol header.
     	 	 To manipulate the IPv4 header, the IP_HDRINCL socket option must be set on the socket.
     	 	 To manipulate the IPv6 header, the IPV6_HDRINCL socket option must be set on the socket.
         */
        HostBuilder setSocketTypeRAW();
        /*
         * SOCK_RDM : 4
     	 	 A socket type that provides a reliable message datagram.
     	 	 An example of this type is the Pragmatic General Multicast (PGM) multicast protocol implementation in Windows,
     	 	 often referred to as reliable multicast programming.
     	 	 This type value is only supported if the Reliable Multicast Protocol is installed.
         */
        HostBuilder setSocketTypeRDM();
        /*
         * SOCK_SEQPACKET : 5
     	 	 A socket type that provides a pseudo-stream packet based on datagrams.
         */
        HostBuilder setSocketTypeSEQPACKET();
    
};


#endif //HOSTFORSOCKET_HOSTBUILDER_H
