#include "Server/server.h"

Server::Server()
{
	socket = IndSocket::createSocket();
	//IndSocket::AFINET, IndSocket::S_STREAM, 0
}

void Server::Start()
{
	while (true)
	{

	}
}
