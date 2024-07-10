// Class for containing and interpriting ip v4 addresses

#include <iostream>

class IpAddr
{

public:
	IpAddr(std::string str_addr);

	std::string ToString() const;

	friend std::ostream& operator<<(std::ostream& os, const IpAddr& obj);

private:
	static const size_t ipaddr_size = 4;
	int addr[ipaddr_size];

	void FromString(std::string str_addr);
};