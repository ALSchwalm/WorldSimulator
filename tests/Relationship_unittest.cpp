#include "gtest/gtest.h"

#include <algorithm>
#include <memory>
#include "Individual/Individual.h"
#include "Individual/SimpleProfession.h"
#include "Location/Village.h"
#include "Relationship/Relationship.h"

TEST(RelationshipTest, Relationships)
{

	auto individual_one = std::make_shared<Actor::Individual>("Person1", true);
	auto individual_two = std::make_shared<Actor::Individual>("Person2", true);
	auto location = std::make_shared<Location::Village>("Village");

	individual_one->addRelationship(location, Relationship::RelationshipType::BIRTHPLACE);

	Relationship::createSymetricRelationship(individual_one, individual_two, Relationship::RelationshipType::FRIEND);
	Relationship::createASymetricRelationship(individual_one, Relationship::RelationshipType::PARENT, individual_two, Relationship::RelationshipType::CHILD);

	EXPECT_TRUE(individual_one->getIndividualRelationshipMap().getRelationships(individual_two).size() == 2);
	EXPECT_TRUE(individual_two->getIndividualRelationshipMap().getRelationships(individual_one).size() == 2);
	EXPECT_TRUE(individual_one->getLocationRelationshipMap().getRelationships(location).size() != 0);
}
