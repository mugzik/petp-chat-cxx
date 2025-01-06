#include "Server/server.h"

#include "Server/clientprocessor.h"

#include <iostream>

Server::Server()
{
	socket = WinSocket();
}

Server::Server(int port, const char *address): port(port), address(address)
{
	socket = WinSocket();
}

void Server::start()
{
	std::cout << "Server has started serving" << std::endl;

	socket.open();
	socket.bind(port, address.c_str());
	socket.listen();

	while (true)
	{
		auto clientSocket = socket.accept();
		if (clientSocket.isValid()) {

			connections.emplace_back(ClientProcessr(clientSocket));
		}
	}
}
