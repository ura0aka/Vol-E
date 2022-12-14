#pragma once


#include "Entity.hpp"

class Entity;

class EntityManager
{
private:
std::vector<std::unique_ptr<Entity>> mEntityContainer {};
std::array<std::vector<Entity*>, maxGroups> mGroupedEntities {};

public:
// == CONSTRUCTOR/DESTRUCTOR ==
EntityManager();
~EntityManager();

// == ENTITY MANAGER FUNCTION(S) ==
Entity& addEntity();

// == GROUP MANAGEMENT ==
void addToGroup(Entity* entity, GroupID group);
std::vector<Entity*>& getEntitiesByGroup(GroupID group);

// == MAIN FUNCTIONS ==
void refreshManager();
void updateManager(const float& dt);
void renderManager(sf::RenderTarget* targetWin);

};



