#pragma once

class IndSocket {

public:
	static int const AFUNSP		= 0;            
	static int const AFUNIX		= 1;               
	static int const AFINET		= 2;

	static int const S_STREAM	= 1;            
	static int const S_DGRAM	= 2;            
	static int const S_RAW		= 3;            

	virtual void open() {};
	virtual void close() {};
	virtual void bind() {};
	virtual void write() {};
	virtual void read() {};

	static IndSocket* createSocket(int af, int type, int protocol);
};


//class UxSocket:Socket
//{
//
//};

