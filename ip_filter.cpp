#include "ip_filter.h"


std::vector<std::string> split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.emplace_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.emplace_back(str.substr(start));

	return r;
}


std::ostream& operator<<(std::ostream& os, IpAddr & ipAddr) {


	for (auto ip_part = ipAddr.cbegin(); ip_part != ipAddr.cend(); ++ip_part)
	{
		if (ip_part != ipAddr.cbegin())
		{
			os << ".";
		}
		os << *ip_part;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, IpList & ipList) {

	for (auto&& iter : ipList) {
		os << iter << "\n";
	}

	return os;
}


IpAddr convert(std::vector<std::string> && str)
{
	IpAddr addr;

	for (auto& iter : str) {
		addr.emplace_back(std::move(std::stoi(iter)));
	}

	return addr;
}


void lexSortRev(IpList& pool) {
	std::sort(pool.rbegin(), pool.rend());
}


IpList filterFirst(const IpList& ippool, const int first_val) {
	IpList pool;
	for (const auto& iter : ippool) {
		if (iter[0] == first_val)
			pool.emplace_back(iter);
	}
	return pool;

}

IpList filterFirstAndSecond(const IpList& ippool, const int first_val, const int second_val) {
	IpList pool;
	for (const auto& iter : ippool) {
		if (iter[0] == first_val && iter[1] == second_val)
			pool.push_back(iter);
	}
	return pool;
}

IpList filterAnyOf(const IpList& ippool, int val) {
	IpList pool;
	for (const auto& iter : ippool)
	{
		if (std::any_of(iter.begin(), iter.end(), [&val](int comp) {return comp == val; }))
			pool.push_back(iter);

	}
	return pool;
}