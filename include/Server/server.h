#pragma once

#include <map>;
#include "Network/socket.h"

class Server {

public:
	Server();
	void Start();

private:
// What we should have here

// connections list
	std::map<int, int> connections;

// socket
	IndSocket* socket;

// port
// ipaddr

// state?

};