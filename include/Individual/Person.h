/*
 * Person.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Event/BaseEvent.h"
#include <string>

namespace Individual
{
	class Person {
	public:
		Person();
		Person(std::string name);

		virtual unsigned int getAge() {return age;};
		virtual const std::string getName() {return name;};

		virtual const Event::EventHistory & getHistory() {return history;};

		virtual void addEvent(Event::BaseEvent *e) {history.push_back(e);};

	private:
		unsigned int age;
		const std::string name;

		Event::EventHistory history;

	};
}
#endif /* PERSON_H_ */
