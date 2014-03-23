
#define BOOST_TEST_MODULE Tests
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/python.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "Utils/Defaults.h"

namespace keywords = boost::log::keywords;

bool setup() {
    boost::log::add_file_log(
        keywords::file_name = "unittests.log",
        keywords::format = "[%TimeStamp%]: %Message%");
    Py_Initialize();
    return Utils::loadPlugins();
}

static bool b = setup();
