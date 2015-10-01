#include "HostBuilder.h"
#include <thread>
#include <fstream>
int main(int argc, char **argv)
{
	std::ofstream file;
	file.open("log.txt");
	ServerHost server = HostBuilder::newInstance()
		.setLogFileWriter(file)
		.setAddress("127.0.0.1")
		.setAddressFamilyIPv4()
		.setPortNumber(12345)
		.setProtocolUDP()
		.setSocketTypeDGRAM()
		.buildServer();
	std::thread serverThread(&ServerHost::listenRequest,server); 
	
	HostBuilder::newInstance()
		.setAddress("127.0.0.1")
		.setPortNumber(8888)
		.setAddressFamilyIPv4()
		.setProtocolUDP()
		.setSocketTypeDGRAM()
		.buildClient()
		.connectServer(server.getServerSocketAddress());

	serverThread.join();
	system("pause");
}