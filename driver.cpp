#include "HostBuilder.h"
#include <thread>
int main(int argc, char **argv)
{
	ServerHost server = HostBuilder::newInstance()
		.setAddress("127.0.0.1")
		.setAddressFamily(AF_INET)
		.setPortNumber(12345)
		.buildServer();
	std::thread serverThread(&ServerHost::listenRequest,server); 
	
	HostBuilder::newInstance()
		.setAddress("127.0.0.1")
		.setPortNumber(8888)
		.setAddressFamily(AF_INET)
		.buildClient()
		.connectServer(server.getServerSocketAddress())
		.sendMessage("Hello");

	serverThread.join();
	system("pause");
}