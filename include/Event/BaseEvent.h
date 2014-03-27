/*
 * Event.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "Event/Event.h"
#include "Time/TimeManager.h"
#include "Time/DateManager.h"
#include <memory>
#include <string>

namespace Action
{
    class Task;
}


namespace Event
{
    class BaseEvent
    {
    public:
        virtual ~BaseEvent(){};

        std::string getEventName() const {return name;}
        virtual EventType getEventType() const {return EVENT_ERROR;}
        Time::Date getExecutionDate() const {return executionDate;}
        Action::Task* getSourceTask() const { return sourceTask; }

        void setExecutionDate(Time::Date newDate) {executionDate = newDate;}
        void setSoonestExecution() {
            auto newTime = Time::now();
            newTime.setMinute(newTime.getMinute()+1);
            executionDate = newTime;
        }
        void setSourceTask(Action::Task* s) {sourceTask = s;}

        virtual void run()=0;

        //An event which takes place over time should implement this
        virtual void interrupt(){};

    protected:
        BaseEvent(std::string s) :
            executionDate(),
            name(s),
            sourceTask(nullptr){}

        BaseEvent(Time::Date t, std::string s) :
            executionDate(t),
            name(s),
            sourceTask(nullptr){}

        Time::Date executionDate;
        std::string name;

        /*
         * The task which ties this event to an individual (possibly)
         * The task will only be destroyed once the goal is completed, and it cannot be completed
         * until a callback from the event, so it should be safe to use a raw pointer.
         */
        Action::Task* sourceTask;
    };

    typedef std::shared_ptr<BaseEvent> Event_ptr;
    typedef std::vector<Event_ptr> EventHistory;

}
#endif /* EVENT_H_ */
