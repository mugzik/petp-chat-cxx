#include "Network/winsocket.h"

#include <iostream>

// init lib
#pragma comment(lib, "Ws2_32.lib")


WinSocket::WinSocket(int af, int type, int protocol)
{
	// init  socket Data
	WSADATA wsData;

	// Start win socket api
	int erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

	if (erStat != 0)
	{
		std::cout << "Error WinSock version initializaion #";
		std::cout << WSAGetLastError();
	}
	else
	{
		std::cout << "WinSock initialization is OK" << std::endl;
	}

	a_socket = socket(af, type, protocol);
}

void WinSocket::open()
{

}

void WinSocket::close()
{

}

void WinSocket::bind()
{

}

void WinSocket::write() 
{

}
void WinSocket::read()
{

}