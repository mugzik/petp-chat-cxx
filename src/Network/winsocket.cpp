#include "Network/winsocket.h"

#include <iostream>

// init lib
#pragma comment(lib, "Ws2_32.lib")


void WinSocket::open(int af, int type, int protocol)
{
	if (!initWSAData())
	{
		return;
	}

	a_socket = socket(af, type, protocol);

	if (a_socket == INVALID_SOCKET)
	{
		logError("Error while initialization");
		close();
	}
	else
	{
		std::cout << "Socket inited ok" << std::endl;
	}
}

void WinSocket::close()
{
	closesocket(a_socket);
	WSACleanup();
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

void WinSocket::logError( const char* message = nullptr )
{
	if ( message != nullptr )
	{
		std::cout << message << std::endl;
	}

	std::cout << WSAGetLastError() << std::endl;
}

bool WinSocket::initWSAData()
{
	// init  socket Data
	WSADATA wsData;

	// Start win socket api
	int erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

	if (erStat != 0)
	{
		logError("Error WinSock version initializaion");
		return false;
	}
	else
	{
		std::cout << "WinSock initialization is OK" << std::endl;
		return true;
	}
}
