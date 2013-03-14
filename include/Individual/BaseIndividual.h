#ifndef BASEINDIVIDUAL_H_
#define BASEINDIVIDUAL_H_

#include "Individual/Individual.h"
#include "Event/Event.h"
#include "Action/GoalTree.h"
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

		BaseIndividual() :
			age(0),
			name("DefaultName"),
			currentLocation (nullptr){}

		BaseIndividual(std::string _name, Location_ptr _location) :
			age(0),
			name(_name),
			currentLocation(_location){}

		typedef Relationship::Relationship<BaseIndividual, BaseIndividual > IIR;
		typedef Relationship::Relationship<BaseIndividual, Location::BaseLocation > ILR;

		std::map<Individual_ptr, std::vector<shared_ptr<IIR>> > IndividualRelationships;
		std::map<Location_ptr, std::vector<shared_ptr<ILR>> > LocationRelationships;

		unsigned int age;
		const std::string name;
		Location_ptr currentLocation;
		std::map<std::string, bool> attributes;

		Event::EventHistory history;

		Action::GoalTree goalTree;
	public:

		virtual Location_ptr getCurrentLocation() { return currentLocation; }
		virtual void setCurrentLocation( Location_ptr c ) { currentLocation = c;}

		virtual unsigned int getAge() {return age;}
		virtual const std::string getName() {return name;}
		virtual const Event::EventHistory & getHistory(){return history;}
		virtual void addEvent(shared_ptr<Event::BaseEvent> e) {history.push_back(e);}

		virtual IndividualType getIndividualType(){ return IndividualType::INDIVIDUAL_ERROR;}

		void addGoal(Action::Goal_ptr g) {goalTree.addGoal(g);}

		bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}


		void addIndividualRelationship(Individual_ptr b, shared_ptr<IIR> r)
		{
			IndividualRelationships[b].push_back(r);
		}

		void addLocationRelationship(Location_ptr b, shared_ptr<ILR> r)
		{
			LocationRelationships[b].push_back(r);
		}

		std::vector<shared_ptr<IIR>> getIndividualRelationships(Individual_ptr i)
		{
			return IndividualRelationships[i];
		}

		std::vector<shared_ptr<ILR>> getLocationRelationships(Location_ptr l)
		{
			return LocationRelationships[l];
		}


	};


}
#endif
