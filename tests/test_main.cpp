
#define BOOST_TEST_MODULE Tests
#include <boost/python.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>

bool setup() {
    Py_Initialize();
    return true;
}

static bool b = setup();
