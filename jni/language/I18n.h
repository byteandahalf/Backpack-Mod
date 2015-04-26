#pragma once
#include <string>
#include <vector>

class I18n {
	public:
	static void get(std::string const&,std::vector<std::string,std::allocator<std::string>> const&);
};