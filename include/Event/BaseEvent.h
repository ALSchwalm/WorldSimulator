/*
 * Event.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include "Event/Event.h"
#include "Time/Date.h"
#include "Time/TimeManager.h"
#include <memory>


namespace Action
{
    class Task;
}


namespace Event
{

    typedef std::shared_ptr<BaseEvent> Event_ptr;

    class BaseEvent
    {
    public:
        virtual ~BaseEvent(){};

        std::string getEventName() const {return name;}
        virtual EventType getEventType() const {return EVENT_ERROR;}
        Time::Date getExecutionDate() const {return executionDate;}
        Action::Task* getSourceTask() const { return sourceTask; }

        void setExecutionDate(Time::Date newDate) {executionDate = newDate;}
        void setSoonestExecution() {executionDate = Time::now()+1;}
        void setSourceTask(Action::Task* s) {sourceTask = s;}

        virtual void run()=0;

        //An event which takes place over time should implement this
        virtual void interrupt(){};

    protected:
        BaseEvent(std::string s) :
            executionDate(Time::Date(0, Time::Month::January, Time::Day::Monday)),
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

}
#endif /* EVENT_H_ */
