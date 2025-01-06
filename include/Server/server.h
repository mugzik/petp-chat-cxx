#pragma once

#include <memory>
#include <thread>
#include <vector>
#include <string>
#include "Network/winsocket.h"

class Server {

public:
	Server();
	Server(int port, const char * address);
	void start();

private:
// connections list
	std::vector<std::jthread> connections;

// socket
	WinSocket socket;

	int port = 5000;
	std::string address = "127.0.0.1";

// state?

};