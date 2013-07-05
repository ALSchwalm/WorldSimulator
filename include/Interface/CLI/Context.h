#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <string>

namespace Interface
{
    namespace CLI
    {
        enum Context
        {
            ALL,
            LOCATION,
            INDIVIDUAL,

            NO_CONTEXT,		//used for <CR>
            NUM_OF_CONTEXTS
        };

        inline std::string contextAsString(Context c)
        {
            switch (c)
            {
            case LOCATION:
                return "Location";
            case INDIVIDUAL:
                return "Individual";
            default:
                return "Error"; //this should never be seen
            }
        }

    }
}

#endif
