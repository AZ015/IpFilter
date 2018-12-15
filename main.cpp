#include <iostream>
#include <vector>
#include<algorithm>

#include "ip_filter.h"


int main(int argc, char const *argv[])

{

	try
	{
		IpList ip_pool;
			for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			ip_pool.emplace_back(convert(split(v.at(0), '.')));
		}

		lexSortRev(ip_pool);

		std::cout << ip_pool;
		auto ip = filterFirst(ip_pool, 1);
		std::cout << ip;
		ip = filterFirstAndSecond(ip_pool, 46, 70);
		std::cout << ip;
		ip = filterAnyOf(ip_pool, 46);
		std::cout << ip;
		
	}

	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

