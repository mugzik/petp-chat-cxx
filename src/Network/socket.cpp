#include "Network/socket.h"
#if defined(_WIN32) || defined(_WIN64)
#include "Network/winsocket.h"

#elif defined(unix)
//#include "Network/uxsocket.h"
#endif


IndSocket* IndSocket::createSocket(int af, int type, int protocol)
{
#if defined(_WIN32) || defined(_WIN64)
	return dynamic_cast<IndSocket*>(new WinSocket(af, type, protocol));
#elif defined(unix)
// Unix implementation
#endif
}