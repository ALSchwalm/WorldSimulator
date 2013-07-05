/*
 * Event.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <Event/Event.h>
#include <Time/Date.h>
#include <memory>

namespace Event
{

    typedef std::shared_ptr<BaseEvent> Event_ptr;

    class BaseEvent
    {
    public:
        virtual ~BaseEvent(){};

        virtual std::string getEventName() {return name;}
        virtual EventType getEventType() {return EVENT_ERROR;}

        virtual Time::Date getExecutionDate(){return executionDate;}
        virtual void setExecutionDate(Time::Date newDate) {executionDate = newDate;}

        virtual void* getSource(){ return nullptr; }

        virtual void run()=0;

        void interrupt();

    protected:
        BaseEvent(std::string s) :
            source(nullptr),
            executionDate(Time::Date(0, Time::Month::January, Time::Day::Monday)),
            name(s){}

        BaseEvent(Time::Date t, std::string s) :
            source(nullptr),
            executionDate(t),
            name(s){}

        void* source;
    private:
        Time::Date executionDate;
        std::string name;



    };

}
#endif /* EVENT_H_ */
