#include "FirstScreen.h"
#include "GameManager.h"

FirstScreen::FirstScreen()
{
	std::vector<GameObject*> gameObjects;
	screen = new Screen();
	gameObjects.push_back(new GameObject(screen->world, b2Vec2(0, 1), b2_staticBody));
	gameObjects.push_back(new GameObject(screen->world, b2Vec2(25, 10), b2_dynamicBody));

	for (GameObject* GO : gameObjects) {
		screen->gameObjectLoc.insert(std::map<GameObject*, sf::Vector2f, decltype(screen->GOcomp)>::value_type(GO, GO->sfShape.getPosition()));
		screen->gameObjects.push_back(GO);
	}

	//screen->gameManager->Load(screen);
}


FirstScreen::~FirstScreen()
{

}
