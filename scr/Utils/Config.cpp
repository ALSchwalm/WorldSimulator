
#include "Utils/Config.h"
#include <iostream>
#include <stdexcept>

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

const unsigned int Config::getValue(std::string section, std::string value)
{
	ini.Select(section);
	auto ini_value = ini.Get(value, -1);
	if (ini_value == -1)
	{
		throw(std::runtime_error(std::string("Unable to locate value for ") + section + std::string(".") + value));
		return 0;
	}
	else
	{
		return ini_value;
	}
}
