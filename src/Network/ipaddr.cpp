#include "Network/ipaddr.h"

#include <string>


IpAddr::IpAddr(std::string str_addr) : addr{}
{
	FromString(str_addr);
}

std::string IpAddr::ToString() const
{
	std::string res = "";

	for (int i = 0; i < ipaddr_size; i++)
	{
		res += std::to_string(addr[i]);
		if (i < ipaddr_size - 1) res += '.';
	}

	return res;
}

void IpAddr::FromString(std::string str_addr)
{
	auto first_symbol = str_addr.begin();

	int counter = 0;

	for ( auto last_symbol = str_addr.begin() ; ; ++last_symbol )
	{
		if (last_symbol == str_addr.end()  || *last_symbol == '.')
		{
			std::string addr_part = std::string(first_symbol, last_symbol);
			if (addr_part == "") 
				break;

			try
			{
				addr[counter] = std::stoi(addr_part);
				++counter;
			}
			catch (const std::exception&)
			{
				throw std::invalid_argument("Wrong IP address");
			}

			if (last_symbol != str_addr.end())
			{
				first_symbol = last_symbol + 1;
			}
			else break;
		}
	}

	if (counter != 4)
	{
		throw std::invalid_argument("Wrong IP address");
	}
}

std::ostream& operator<<(std::ostream& os, const IpAddr& obj)
{
	os << obj.ToString();
	return os;
}
