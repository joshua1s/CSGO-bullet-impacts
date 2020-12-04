#pragma once
#include "virtual method.hpp"

class Entity
{
public:
	VIRTUAL(int, index, 10, (), (this + 8))
};

class EntityList
{
public:
	VIRTUAL(Entity*, getEntity, 3, (int index), (this, index))
};