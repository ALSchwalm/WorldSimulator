#ifndef TOOL_H_
#define TOOL_H_

#include "Item/BaseItem.h"

namespace Item
{

    class BaseTool : public virtual BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::TOOL;}

        virtual ~BaseTool(){}

    private:

    };

    class BaseToolPy : public BaseItemPy, public BaseTool
    {
    public:
        BaseToolPy(PyObject *p, std::string _name) : BaseItem(_name),
                                                     BaseItemPy(p) {}
    };
}

#endif
