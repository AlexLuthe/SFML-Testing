#pragma once
#ifndef __B2D__
#define __B2D__
#include <Box2D\Box2D.h>
#endif

class World
{
public:
	World();
	World(b2Vec2 gravity);
	~World();
	b2World* Get();

	b2Vec2 _gravity;
	b2World* _world;
	float sfmlScaler;
};

