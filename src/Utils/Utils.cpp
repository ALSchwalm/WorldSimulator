#include "Utils/Utils.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace Utils {
    namespace Logging {
        void initialize() {
            boost::log::add_file_log(
                boost::log::keywords::file_name = "logfile.log",
                boost::log::keywords::format = "[%TimeStamp%]: %Message%");
        }
    }
}
