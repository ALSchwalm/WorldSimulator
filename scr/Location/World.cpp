
#include "Location/World.h"
#include <iostream>
#include <memory>

using namespace Location;

//There can only be one world (for now)
Location_ptr & World::getInstance()
{
	return make_shared<
}


World::World() : BaseLocation(nullptr)
{

}

World::~World()
{

}

void World::addItem(Item::Item_ptr i)
{
	std::cerr << "Error: Attempt to add item to 'world' instance." << std::endl;
}
void World::operator+=(Item::Item_ptr rhs)
{
	std::cerr << "Error: Attempt to add item to 'world' instance." << std::endl;
}
void World::addIndividual(Individual::Individual_ptr i)
{
	std::cerr << "Error: Attempt to add individual to 'world' instance." << std::endl;
}

void World::operator+=(Individual::Individual_ptr rhs)
{
	std::cerr << "Error: Attempt to add individual to 'world' instance." << std::endl;
}
