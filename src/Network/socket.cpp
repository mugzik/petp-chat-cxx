#include "Network/socket.h"
#if defined(_WIN32) || defined(_WIN64)
#include "Network/winsocket.h"

#elif defined(unix)
//#include "Network/uxsocket.h"
#endif


IndSocket* IndSocket::createSocket()
{
#if defined(_WIN32) || defined(_WIN64)
	return dynamic_cast<IndSocket*>(new WinSocket());
#elif defined(unix)
// Unix implementation
#endif
}