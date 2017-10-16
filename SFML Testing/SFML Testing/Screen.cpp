#include "Screen.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Conversion.h"
#include <map>


Screen::Screen()
{
	world = new World(b2Vec2(0, 10));
	GameManager* gameManager = new GameManager(world);
}

Screen::~Screen()
{
	delete world;
}
