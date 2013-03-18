#ifndef EVENT_H_
#define EVENT_H_

#include <vector>
#include <memory>

namespace Event
{
	class BaseEvent;

	enum EventType
	{
		BIRTH_EVENT,
		END_TASK_EVENT,
		MOVE_EVENT,
		PICKUP_EVENT,

		//Insert events before this
		EVENT_ERROR,
		NUM_OF_EVENTS
	};

	typedef std::vector<std::shared_ptr<BaseEvent>> EventHistory;

}
#endif
