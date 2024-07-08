#include <WinSock2.h>
#include <WS2tcpip.h>

class Socket
{
public:
	virtual void open();
	virtual void close();
	virtual void bind();
	virtual void write();
	virtual void read();
};

class WinSocket:Socket
{
public:
	WinSocket();
	void open();
	void close();
	void bind();
	void write();
	void read();

private:
	SOCKET socket;
};

class UxSocket:Socket
{

};

