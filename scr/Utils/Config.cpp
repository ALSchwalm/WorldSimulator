
#include "Utils/Config.h"
#include <iostream>

using namespace Utils;

Config & Config::getInstance()
{
	static Config c;
	return c;
}

Config::Config() :
	ini(std::string("config.ini"), true)
{
};

const int Config::getValue(std::string section, std::string value)
{
	ini.Select(section);
	auto ini_value = ini.Get(value, -1);
	if (ini_value == -1)
	{
		std::cerr << std::string("Unable to locate value for ") + section + std::string(".") + value << std::endl;
		exit(0);
		return 0;
	}
	else
	{
		return ini_value;
	}
}
