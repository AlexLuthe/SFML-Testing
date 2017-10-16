#include "GameManager.h"

GameManager::GameManager() {

}

GameManager::GameManager(World* _world)
{
	world = _world;
	GameObject* GO = new GameObject(world, b2Vec2(25, 10), b2_dynamicBody);
	gameObjects.push_back(GO);
}


GameManager::~GameManager()
{
	for (GameObject* GO : gameObjects)
		delete GO;
}

void GameManager::Update(float deltaTime) {
	for (GameObject* obj : gameObjects)
		obj->Update(deltaTime);
}

void GameManager::Load(Screen* screen) {

}
