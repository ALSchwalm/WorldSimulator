#ifndef CONVERSION_H
#define CONVERSION_H

#include "Item/BaseItem.h"
#include <boost/python/handle.hpp>
#include <boost/python/converter/shared_ptr_deleter.hpp>
#include <boost/python/converter/from_python.hpp>
#include <boost/python/converter/rvalue_from_python_data.hpp>
#include <boost/python/converter/registered.hpp>
#include <boost/python.hpp>
#include <memory>

namespace boost { namespace python { namespace converter {
template <class T>
struct std_shared_ptr_from_python
{
    std_shared_ptr_from_python()
    {
        converter::registry::insert(&convertible, &construct, type_id<std::shared_ptr<T> >(),
                                    &converter::expected_from_python_type_direct<T>::get_pytype);
    }

 private:
    static void* convertible(PyObject* p)
    {
        if (p == Py_None)
            return p;

        return converter::get_lvalue_from_python(p, registered<T>::converters);
    }

    static void construct(PyObject* source, rvalue_from_python_stage1_data* data)
    {
        void* const storage = ((converter::rvalue_from_python_storage<std::shared_ptr<T> >*)data)->storage.bytes;
        // Deal with the "None" case.
        if (data->convertible == source)
            new (storage) std::shared_ptr<T>();
        else
        {
            std::shared_ptr<void> hold_convertible_ref_count(
              (void*)0, shared_ptr_deleter(handle<>(borrowed(source))) );
            // use aliasing constructor
            new (storage) std::shared_ptr<T>(
                hold_convertible_ref_count,
                static_cast<T*>(data->convertible));
        }

        data->convertible = storage;
    }
};
        }}}

namespace Utils
{
    using namespace boost::python;
    using namespace Item;

    void setupConversions() {
        ///Conversion   shared_ptr<BaseItem> <-> PyObject
        converter::std_shared_ptr_from_python<BaseItem>();
        objects::class_value_wrapper<
            std::shared_ptr<BaseItem>
            , objects::make_ptr_instance<BaseItem, objects::pointer_holder<std::shared_ptr<BaseItem>,BaseItem> >
            >();
    }
}

#endif
