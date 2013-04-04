#ifndef BASEINDIVIDUAL_H_
#define BASEINDIVIDUAL_H_

#include "Individual/Individual.h"
#include "Event/Event.h"
#include "Item/BaseItem.h"
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
		BaseIndividual(std::string _name) :
			age(0),
			name(_name),
			currentLocation (nullptr),
			goalTree(std::make_shared<BaseIndividual>(*this)){} //FIXME review this

		BaseIndividual(std::string _name, Location_ptr _location) :
			age(0),
			name(_name),
			currentLocation(_location),
			goalTree(std::make_shared<BaseIndividual>(*this)){}

		typedef Relationship::Relationship<BaseIndividual, BaseIndividual > IIR;
		typedef Relationship::Relationship<BaseIndividual, Location::BaseLocation > ILR;

		std::map<Individual_ptr, std::vector<shared_ptr<IIR>> > IndividualRelationships;
		std::map<Location_ptr, std::vector<shared_ptr<ILR>> > LocationRelationships;

		std::vector<Item::Item_ptr> items;
		unsigned int age;
		const std::string name;
		Location_ptr currentLocation;
		std::map<std::string, bool> attributes;

		Event::EventHistory history;

		Action::GoalTree goalTree;
	public:
		virtual ~BaseIndividual(){}

		Location_ptr getCurrentLocation() { return currentLocation; }
		void setCurrentLocation( Location_ptr c ) { currentLocation = c;}

		unsigned int getAge() {return age;}
		const std::string getName() {return name;}
		const Event::EventHistory & getHistory(){return history;}
		const std::vector<Item::Item_ptr> & getItems() {return items;}
		virtual IndividualType getIndividualType(){ return IndividualType::INDIVIDUAL_ERROR;}

		void addEvent(shared_ptr<Event::BaseEvent> e) {history.push_back(e);}
		void addItem(Item::Item_ptr i) {items.push_back(i);}

		void addGoal(Action::GoalRequest _goalRequest, unsigned int _priority)
		{
			goalTree.addGoal(_goalRequest,  _priority);
		}
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

		void setAttribute(std::string s) {attributes[s] = true;}
		bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}
		bool removeItem(Item::Item_ptr i);

	};


}
#endif
