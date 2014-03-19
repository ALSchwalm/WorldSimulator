#ifndef UTILS_H
#define UTILS_H

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace Utils
{
    namespace Logging
    {
        inline void initialize() {
            boost::log::add_file_log("sample.log");
        }
    }
}

#endif
