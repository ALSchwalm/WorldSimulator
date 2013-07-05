#ifndef EVENT_H_
#define EVENT_H_

#include <vector>
#include <memory>

namespace Event
{
    class BaseEvent;

    enum EventType
    {
        BIRTH,
        END_TASK,
        MOVE,
        PICKUP,
        INTERRUPT,

        //Insert events before this
        EVENT_ERROR,
        NUM_OF_EVENTS
    };

    typedef std::vector<std::shared_ptr<BaseEvent>> EventHistory;

}
#endif
