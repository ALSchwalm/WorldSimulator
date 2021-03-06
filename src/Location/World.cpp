
#include "Location/World.h"
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace Location;

//There can only be one world (for now)
Location_ptr World::getInstance()
{
    static auto world = std::make_shared<World>();
    return world;
}


World::World() : BaseLocation("World")
{

}

World::~World()
{

}

void World::addItem(Item::Item_ptr)
{
    throw(std::runtime_error("Attempt to add item to 'world' instance."));
}

void World::addIndividual(Actor::Individual_ptr)
{
    throw(std::runtime_error("Attempt to add individual to 'world' instance."));
}
