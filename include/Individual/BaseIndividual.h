#ifndef BASEINDIVIDUAL_H_
#define BASEINDIVIDUAL_H_

#include "Individual/Individual.h"
#include "Event/Event.h"
#include "Item/BaseItem.h"
#include "Action/GoalTree.h"
#include "Relationship/Relationship.h"
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

namespace Individual
{
	using Location::Location_ptr;

	class BaseIndividual
	{
	protected:
		BaseIndividual(std::string _name, bool _isMale=true) :
			age(0),
			name(_name),
			isMale(_isMale),
			currentLocation (nullptr),
			goalTree(std::make_shared<BaseIndividual>(*this)){} //FIXME review this

		BaseIndividual(std::string _name, Location_ptr _location, bool _isMale=true) :
			age(0),
			name(_name),
			isMale(_isMale),
			currentLocation(_location),
			goalTree(std::make_shared<BaseIndividual>(*this)){}


		Relationship::RelationshipMap<Individual_ptr> IndividualRelationshipMap;
		Relationship::RelationshipMap<Location_ptr> LocationRelationshipMap;

		std::vector<Item::Item_ptr> items;
		unsigned int age;
		const std::string name;
		bool isMale;
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
		Relationship::RelationshipMap<Individual_ptr> & getIndividualRelationshipMap() {return IndividualRelationshipMap;}
		Relationship::RelationshipMap<Location_ptr> & getLocationRelationshipMap() {return LocationRelationshipMap;}

		virtual IndividualType getIndividualType(){ return IndividualType::INDIVIDUAL_ERROR;}

		void addEvent(shared_ptr<Event::BaseEvent> e) {history.push_back(e);}
		void addItem(Item::Item_ptr i) {items.push_back(i);}
		void addGoal(Action::GoalRequest _goalRequest, unsigned int _priority);
		void addRelationship(Location_ptr location, Relationship::RelationshipType rel);
		void addRelationship(Individual_ptr individual, Relationship::RelationshipType rel);

		void setAttribute(std::string s) {attributes[s] = true;}
		bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}
		bool removeItem(Item::Item_ptr i);

	};
	typedef std::shared_ptr<BaseIndividual> Individual_ptr;
	typedef std::vector<std::shared_ptr<Individual::BaseIndividual>> IndividualList;

}
#endif
