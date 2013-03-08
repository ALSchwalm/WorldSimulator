#ifndef BASEINDIVIDUAL_H_
#define BASEINDIVIDUAL_H_

#include "Individual/Individual.h"
#include "Event/Event.h"
#include <string>
#include <map>
#include <utility>
#include <memory>

using std::shared_ptr;

namespace Location
{
	class BaseLocation;
	typedef shared_ptr<BaseLocation> Location_ptr;
}

namespace Relationship
{
	template <typename T, typename U>
	class Relationship;
}


namespace Individual
{
	typedef std::shared_ptr<BaseIndividual> Individual_ptr;
	using Location::Location_ptr;

	class BaseIndividual
	{
	protected:
		virtual ~BaseIndividual(){}

		BaseIndividual() : age(0), name("DefaultName"){}
		BaseIndividual(std::string _name) : age(0), name(_name){}

		typedef Relationship::Relationship<BaseIndividual, BaseIndividual > IIR;
		typedef Relationship::Relationship<BaseIndividual, Location::BaseLocation > ILR;

		std::map<Individual_ptr, std::vector<shared_ptr<IIR>> > IndividualRelationships;
		std::map<Location_ptr, std::vector<shared_ptr<ILR>> > LocationRelationships;

		unsigned int age;
		const std::string name;

		Event::EventHistory history;
	public:

		virtual unsigned int getAge() {return age;}
		virtual const std::string getName() {return name;}
		virtual const Event::EventHistory & getHistory(){return history;}
		virtual void addEvent(shared_ptr<Event::BaseEvent> e) {history.push_back(e);}

		virtual IndividualType getIndividualType(){ return IndividualType::INDIVIDUAL_ERROR;}

		virtual void addIndividualRelationship(Individual_ptr b, shared_ptr<IIR> r)
		{
			IndividualRelationships[b].push_back(r);
		}

		virtual void addLocationRelationship(Location_ptr b, shared_ptr<ILR> r)
		{
			LocationRelationships[b].push_back(r);
		}

		virtual std::vector<shared_ptr<IIR>> getIndividualRelationships(Individual_ptr i)
		{
			return IndividualRelationships[i];
		}

		virtual std::vector<shared_ptr<ILR>> getLocationRelationships(Location_ptr l)
		{
			return LocationRelationships[l];
		}


	};


}
#endif
