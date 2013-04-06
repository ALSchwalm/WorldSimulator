#ifndef BASETASK_H_
#define BASETASK_H_

#include <memory>
#include "Event/BaseEvent.h"

namespace Action
{
	class Goal;
	typedef std::shared_ptr<Goal> Goal_ptr;

	class Task
	{
	public:
		Task(Event::Event_ptr, Goal_ptr);
		virtual ~Task();

		//if true, place event in eventQueue
		//returns false if preconditions are not satisfied
		bool run();
		void finished();
		void interrupt();

	private:
		Event::Event_ptr event;
		Goal_ptr goal;
		bool interrupted; //stop EndtaskEvent from creating problems

	};

	typedef std::shared_ptr<Task> Task_ptr;

}

#endif
