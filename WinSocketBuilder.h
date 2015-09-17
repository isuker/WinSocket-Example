#include<winsock.h>
class WinSocketBuilder{
private:
	const static int SUCCESS = 0;
	const static int ERROR_RESULT = 1;
	static WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);
	int addressFamily = AF_INET;
	int socketType = SOCK_STREAM;
	int protocolType = IPPROTO_TCP;
public:
	static WinSocketBuilder* newInstance() throw (int);
	/*
	  	setAddressFamily(int addressFamily)
	    @parameter: int
	 
	  	The address family specification. Possible values for the address family are defined in the Winsock2.h header file.
	  	The address family are listed below:
	  	
			AF_UNSPEC : 0
					The address family is unspecified.
			AF_INET   : 2
					The Internet Protocol version 4 (IPv4) address family.
			AF_IPX	  : 6
					The IPX/SPX address family. This address family is only supported if the NWLink IPX/SPX NetBIOS Compatible Transport protocol is installed.
					This address family is not supported on Windows Vista and later.
			AF_APPLETALK  : 16
					The AppleTalk address family. This address family is only supported if the AppleTalk protocol is installed.
					This address family is not supported on Windows Vista and later.
			AF_NETBIOS    : 17
					The NetBIOS address family. This address family is only supported if the Windows Sockets provider for NetBIOS is installed.
					The Windows Sockets provider for NetBIOS is supported on 32-bit versions of Windows. This provider is installed by default on 32-bit versions of Windows.
					The Windows Sockets provider for NetBIOS is not supported on 64-bit versions of windows including Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP.
					The Windows Sockets provider for NetBIOS only supports sockets where the type parameter is set to SOCK_DGRAM.
					The Windows Sockets provider for NetBIOS is not directly related to the NetBIOS programming interface. The NetBIOS programming interface is not supported on Windows Vista, Windows Server 2008, and later.
			AF_INET6 : 23
					The Internet Protocol version 6 (IPv6) address family.
			AF_IRDA : 26
					The Infrared Data Association (IrDA) address family.
					This address family is only supported if the computer has an infrared port and driver installed.
			AF_BTH : 32
				The Bluetooth address family.
				This address family is supported on Windows XP with SP2 or later if the computer has a Bluetooth adapter and driver installed. 		
	*/
	WinSocketBuilder* setAddressFamily(int addressFamily);
	/*
		
	*/
	WinSocketBuilder* setSocketType(int socketType);
	WinSocketBuilder* setProtocol(int protocolType);
	SOCKET build() throw(int);
};