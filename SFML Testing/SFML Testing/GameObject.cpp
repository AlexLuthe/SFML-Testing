#include "GameObject.h"
#include "World.h"
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "Conversion.h"
#include <iostream>


GameObject::GameObject() {

}

GameObject::GameObject(World* _world, b2Vec2 position, b2BodyType type)
{
	world = _world;
	bodyDef.type = type;
	bodyDef.position = position;
	body = world->_world->CreateBody(&bodyDef);
	bShape.SetAsBox(1.5f, 1.5f);
	fixtureDef.shape = &bShape;
	fixtureDef.density = 1;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
	sfShape.setSize(sf::Vector2f(metretoPixel(2 * bShape.m_vertices[2].x, world->sfmlScaler), metretoPixel(2 * bShape.m_vertices[2].y, world->sfmlScaler)));
	sfShape.setOrigin(sf::Vector2f(metretoPixel(2 * bShape.m_vertices[2].x, world->sfmlScaler), metretoPixel(2 * bShape.m_vertices[2].y, world->sfmlScaler)));
	sfShape.setPosition(sf::Vector2f(metretoPixel(body->GetPosition().x, world->sfmlScaler), metretoPixel(body->GetPosition().y, world->sfmlScaler)));
	sfShape.setFillColor(sf::Color::Blue);
}

GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime) {

}

void GameObject::Draw(sf::RenderWindow& window) {
	sfShape.setPosition(sf::Vector2f(metretoPixel(body->GetPosition().x, world->sfmlScaler), metretoPixel(body->GetPosition().y, world->sfmlScaler)));
	window.draw(sfShape);
	//std::cout << "SFMLPos: " << sfShape.getPosition().x << ", " << sfShape.getPosition().y << std::endl;
	//std::cout << "B2DPos: " << body->GetPosition().x << ", " << body->GetPosition().y << std::endl;
}
