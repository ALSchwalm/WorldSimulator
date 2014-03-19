#ifndef CONFIG_H
#define CONFIG_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Utils
{
    class Config
    {
    public:
        static Config& getInstance();

        template<typename T = unsigned int>
        T getValue(const std::string& name) {
            return pt.get<T>(name);
        }
    private:
        Config() {
            boost::property_tree::ini_parser::read_ini("config.ini", pt);
        }
        boost::property_tree::ptree pt;
    };
}

#endif
