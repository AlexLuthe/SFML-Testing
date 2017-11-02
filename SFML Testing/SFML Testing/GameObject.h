#pragma once
#ifndef __World__
#define __World__
#include "World.h"
#endif // !__World__
#ifndef __SFG__
#define __SFG__
#include <SFML\Graphics.hpp>
#endif


class GameObject
{
public:
	GameObject();
	GameObject(World* world, b2Vec2 position = b2Vec2(0, 0), b2BodyType type = b2_dynamicBody);
	virtual ~GameObject();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	// Operators
	bool operator< (const GameObject& rhs) { return body->GetPosition().x < rhs.body->GetPosition().x; }
	bool operator> (const GameObject& rhs) { return body->GetPosition().x > rhs.body->GetPosition().x; }

	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape bShape;
	b2FixtureDef fixtureDef;
	sf::RectangleShape sfShape;
	World* world;
};

