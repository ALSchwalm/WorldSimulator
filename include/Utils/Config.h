#ifndef CONFIG_H
#define CONFIG_H

#include "Utils/INI.h"

namespace Utils
{
	class Config
	{
	public:
		static Config & getInstance();
		const int getValue(std::string, std::string);
	private:
		typedef INI <std::string, std::string, int> ini_t;
		ini_t ini;
		Config();
	};
}

#endif
