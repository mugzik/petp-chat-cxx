#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>

#include "socket.h"

class WinSocket : public IndSocket {
public:
	WinSocket() : a_socket(INVALID_SOCKET) {};
	void open(int af, int type, int protocol);
	void close();
	void bind();
	void write();
	void read();

	void logError( const char* message );

private:
	SOCKET a_socket;

	bool initWSAData();
};