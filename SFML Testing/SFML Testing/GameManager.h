#pragma once
#ifndef __GameObject__
#define __GameObject__
#include "GameObject.h"
#endif
#ifndef __SCREEN__
#define __SCREEN__
#include "Screen.h"
#endif
#include "FirstScreen.h"
#include <vector>
class GameManager
{
public:
	World* world;
	GameManager();
	GameManager(World* world);
	~GameManager();
	void Update(float deltaTime);
	void Load(Screen* screen);
	FirstScreen* screen1 = new FirstScreen();

	std::vector<GameObject*> gameObjects;
};

