#ifndef BASEINDIVIDUAL_H_
#define BASEINDIVIDUAL_H_

#include "Individual/Individual.h"
#include "Event/Event.h"
#include <string>

namespace Individual
{
	class BaseIndividual
	{
	public:

		virtual unsigned int getAge() {return age;}
		virtual const std::string getName() {return name;}
		virtual const Event::EventHistory & getHistory(){return history;}
		virtual void addEvent(std::shared_ptr<Event::BaseEvent> e) {history.push_back(e);}

		virtual IndividualType getIndividualType(){ return IndividualType::INDIVIDUAL_ERROR;}

	protected:

		virtual ~BaseIndividual(){}

		BaseIndividual() : age(0), name("none"){}
		BaseIndividual(std::string _name) : age(0), name(_name){}

		unsigned int age;
		const std::string name;

		Event::EventHistory history;



	};


}
#endif
