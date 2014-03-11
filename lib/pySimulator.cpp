#include <boost/python.hpp>
#include <memory>

using namespace boost::python;

BOOST_PYTHON_MODULE(Simulator) {
    class_<BaseItem,
           boost::noncopyable,
           std::shared_ptr<BaseItemWrapper>>("BaseItem", init<>())
        .def("getAttributes", &BaseItem::getAttributes);
}
