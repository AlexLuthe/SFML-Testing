#pragma once
#ifndef __Map__
#define __Map__
#include <map>
#endif // !__Map__
#ifndef __SF__
#define __SF__
#include <SFML/Graphics.hpp>
#endif
#ifndef __GO__
#define __GO__
#include "GameObject.h"
#endif
//#ifndef __GM__
//#define __GM__
#include "GameManager.h"
//#endif
#include <functional>

class Screen
{
public:
	Screen();
	virtual ~Screen();
	std::function < bool(GameObject*, GameObject*) > GOcomp = [](const GameObject* lhs, const GameObject* rhs) { return lhs->body->GetPosition().x < rhs->body->GetPosition().x; };
	std::map < GameObject*, sf::Vector2f, decltype(GOcomp) > gameObjectLoc;
	std::vector<GameObject*> gameObjects;

	World* world;
};

