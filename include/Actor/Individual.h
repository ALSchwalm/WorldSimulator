#ifndef BASEINDIVIDUAL_H_
#define BASEINDIVIDUAL_H_

#include "Profession/ProfessionUtils.h"
#include "Action/GoalTree.h"
#include "Relationship/Relationship.h"
#include "Actor/Disease.h"
#include "Event/BaseEvent.h"
#include <map>
#include <memory>
#include <array>

using std::shared_ptr;

namespace Skill
{
    enum class SkillType: int;
}

namespace Item
{
    class BaseItem;
    typedef shared_ptr<BaseItem> Item_ptr;
}

namespace Location
{
    class BaseLocation;
    typedef shared_ptr<BaseLocation> Location_ptr;
}

namespace Actor
{
    using Location::Location_ptr;

    class Individual
    {
    protected:
        Relationship::RelationshipMap<Individual_ptr> IndividualRelationshipMap;
        Relationship::RelationshipMap<Location_ptr> LocationRelationshipMap;

        std::vector<Item::Item_ptr> items;

        Profession::Profession_ptr profession;
        unsigned int age;
        const std::string name;
        bool isMale;
        Location_ptr currentLocation;
        std::map<std::string, bool> attributes;

        Event::EventHistory history;

        Action::GoalTree goalTree;
        Skill::skillMap skillMap;

        std::array<unsigned int, NUM_OF_STATS>stats;

        std::vector<Disease> diseases;

    public:
        Individual(std::string _name,
                   Location_ptr _location = nullptr,
                   Profession::Profession_ptr p = Profession::getRandomProfession(),
                   bool _isMale = true);

        Individual& operator=(const Individual&) = delete;
        Individual(const Individual&) = delete;

        virtual ~Individual(){}

        Location_ptr getCurrentLocation() { return currentLocation; }
        void setCurrentLocation(Location_ptr c) { currentLocation = c;}

        unsigned int getAge() const {return age;}
        const std::string& getName() const {return name;}
        const Event::EventHistory& getHistory() const {return history;}
        const std::vector<Item::Item_ptr>& getItems() const {return items;};
        Relationship::RelationshipMap<Individual_ptr>& getIndividualRelationshipMap() {return IndividualRelationshipMap;};
        Relationship::RelationshipMap<Location_ptr>& getLocationRelationshipMap() {return LocationRelationshipMap;};
        Profession::Profession_ptr getProfession() const {return profession;}
        Action::GoalTree* getGoalTree() {return &goalTree;}
        std::vector<Disease>& getDiseases() {return diseases;}

        //TODO decide whether this should be added with the profession skill
        const Skill::skillMap& getSkillMap() {return skillMap;}
        float getSkillLevel(Skill::SkillType s);

        void addEvent(Event::Event_ptr e) {history.push_back(e);}
        void addItem(Item::Item_ptr i) {items.push_back(i);}

        void addRelationship(Location_ptr location, Relationship::RelationshipType rel);
        void addRelationship(Individual_ptr individual, Relationship::RelationshipType rel);

        void setAttribute(std::string s) {attributes[s] = true;}
        bool hasAttribute(std::string s) const {return attributes.find(s) != attributes.end();}
        void setSkill(Skill::SkillType s, float f){skillMap[s] = f;}
        bool removeItem(Item::Item_ptr i);

        unsigned int calculatePriority(Individual_ptr, Action::GoalType);

    };

    typedef std::shared_ptr<Individual> Individual_ptr;
    typedef std::vector<Individual_ptr> IndividualList;

}
#endif
