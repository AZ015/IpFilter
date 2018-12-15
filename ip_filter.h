#pragma once



#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<algorithm>



using IpAddr = std::vector<int>;
using IpList = std::vector<IpAddr>;


std::vector<std::string> split(const std::string &str, char d);
std::ostream& operator<<(std::ostream& os, IpAddr & ipAddr);
std::ostream& operator<<(std::ostream& os, IpList & ipList);
IpAddr convert(std::vector<std::string>&& str);
void lexSortRev(IpList& pool);
IpList filterFirst(const IpList& ippool, const int first_val);
IpList filterFirstAndSecond(const IpList& ippool, const int first_val, const int second_val);
IpList filterAnyOf(const IpList& ippool, const int val);

