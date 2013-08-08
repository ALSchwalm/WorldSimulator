#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <string>

namespace Interface
{
    namespace CLI
    {
        enum class Context
        {
            ALL,
            LOCATION,
            INDIVIDUAL,

            NO_CONTEXT,		//used for <CR>
            SAME,
            NUM_OF_CONTEXTS
        };

        inline std::string contextAsString(Context c)
        {
            switch (c)
            {
            case Context::LOCATION:
                return "Location";
            case Context::INDIVIDUAL:
                return "Individual";
            default:
                return "Error"; //this should never be seen
            }
        }

    }
}

#endif
