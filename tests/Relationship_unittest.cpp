#include "Actor/Individual.h"
#include "Profession/SimpleProfession.h"
#include "Location/Village.h"
#include "Relationship/Relationship.h"
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <memory>

BOOST_AUTO_TEST_SUITE(Relationship)

BOOST_AUTO_TEST_CASE(Relationships)
{

	auto individual_one = std::make_shared<Actor::Individual>("Person1", Profession::BAKER);
	auto individual_two = std::make_shared<Actor::Individual>("Person2", Profession::BAKER);
	auto location = std::make_shared<Location::Village>("Village");

	individual_one->addRelationship(location, Relationship::RelationshipType::BIRTHPLACE);

	Relationship::createSymetricRelationship(individual_one, individual_two, Relationship::RelationshipType::FRIEND);
	Relationship::createASymetricRelationship(individual_one, Relationship::WIFE, individual_two, Relationship::HUSBAND);

	BOOST_CHECK_EQUAL(individual_one->getIndividualRelationshipMap().getRelationships(individual_two).size(), 2);
	BOOST_CHECK_EQUAL(individual_two->getIndividualRelationshipMap().getRelationships(individual_one).size(), 2);
	BOOST_CHECK(individual_one->getLocationRelationshipMap().getRelationships(location).size() != 0);
}

BOOST_AUTO_TEST_SUITE_END()
