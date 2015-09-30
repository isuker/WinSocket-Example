#include"HostBuilder.h"
class UDPHostBuilder : public HostBuilder{
	virtual ServerHost buildServer() override;
	virtual ClientHost buildClient() override;
};