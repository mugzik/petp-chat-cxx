#include "Network/winsocket.h"

#include <iostream>

// init lib
#pragma comment(lib, "Ws2_32.lib")


void WinSocket::open()
{
	// open default
	open(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

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

void WinSocket::bind(int port, const char* addr)
{
	sockaddr_in service;

	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(addr);
	service.sin_port = htons(port);

	int result = ::bind(a_socket, ( SOCKADDR * ) &service, sizeof( service ) );
	if (result == SOCKET_ERROR) 
	{
		logError("bind failed with error " + WSAGetLastError());
		closesocket(a_socket);
		WSACleanup();
		throw "Bind error";
	}
}

void WinSocket::listen()
{
	if ( ::listen(a_socket, SOMAXCONN) == SOCKET_ERROR ) 
	{
		logError("Listen failed with error: " + WSAGetLastError());
		closesocket(a_socket);
		WSACleanup();
	}
}

bool WinSocket::isValid()
{

    return a_socket != INVALID_SOCKET;
}

WinSocket WinSocket::accept()
{
	SOCKET clientSocket = INVALID_SOCKET;

	// Accept a client socket
	clientSocket = ::accept(a_socket, NULL, NULL);
	if (clientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(a_socket);
		WSACleanup();
	}

	return WinSocket(clientSocket);
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
