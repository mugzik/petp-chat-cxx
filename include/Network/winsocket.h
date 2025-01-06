#pragma once

#include <memory>

#include <WinSock2.h>
#include <WS2tcpip.h>


class WinSocket {
public:
	WinSocket() : a_socket(INVALID_SOCKET) {};
	WinSocket(SOCKET socket) : a_socket(socket) {};
	~WinSocket() = default;

	void open();
	void open(int af, int type, int protocol);
	void close();
	void bind(int port, const char* addr);
	void write();
	void read();
	void listen();
	bool isValid();
	WinSocket accept();

	void logError( const char* message );

private:
	SOCKET a_socket;

	bool initWSAData();
};