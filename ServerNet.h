#include <stdio.h>
#include <winsock.h>

#pragma comment (lib,"ws2_32.lib")

class CServerNet
{
public:

	//��ʼ��������,����0��ʾ�ɹ�
	int Init(const char* address, int port);

	//��������
	void Run();


private:
	SOCKET m_sock;
};