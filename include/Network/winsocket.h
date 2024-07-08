#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>

#include "socket.h"

class WinSocket : public IndSocket {
public:
	WinSocket(int af, int type, int protocol);
	void open();
	void close();
	void bind();
	void write();
	void read();

private:
	SOCKET a_socket;
};