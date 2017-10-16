#include "World.h"

World::World() {
	_gravity = b2Vec2(0.0f, 10.0f);
	_world = new b2World(_gravity);
	sfmlScaler = 12.8f;
}

World::World(b2Vec2 gravity)
{
	_gravity = b2Vec2(gravity);
	_world = new b2World(_gravity);
	sfmlScaler = 12.8f;
}


World::~World()
{
	delete _world;
}

b2World* World::Get() {
	return _world;
}