#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Conversion.h"
#include "GameManager.h"
#include "World.h"
#include "GameObject.h"
#include <iostream>

int main() {
	float32 timeStep = 1.0f / 60.0f;
	sf::Clock deltaTime;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	World* world = new World(b2Vec2(0.0f, 10.0f));
	GameManager* gameManager = new GameManager(world);

	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Works!");
	
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type = sf::Event::Closed)
				window.close();
		}

		// Physics
		if (deltaTime.getElapsedTime().asSeconds() > timeStep) {
			
			gameManager->Update(deltaTime.getElapsedTime().asMilliseconds());
			world->_world->Step(timeStep, velocityIterations, positionIterations);
			deltaTime.restart();
		}

		// Draw
		window.clear();
		for (GameObject* obj : gameManager->gameObjects) {
			obj->Draw(window);
		}
		window.display();
	}
	delete gameManager;
}













































//#include <SFML\Graphics.hpp>
//#include <Box2D\Box2D.h>
//#include "Conversion.h"
//
//int main() {
//
//	float32 timeStep = 1.0f / 60.0f;
//	sf::Clock deltaTime;
//	int32 velocityIterations = 6;
//	int32 positionIterations = 2;
//	float scaler = 12.8f;
//
//	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Works!");
//	sf::RectangleShape rect(sf::Vector2f(30, 30));
//	//sf::RectangleShape ground(sf::Vector2f(640, 10));
//	//ground.setPosition(sf::Vector2f(0, 470));
//	//ground.setFillColor(sf::Color::Green);
//	rect.setFillColor(sf::Color::Red);
//
//	// Box2D
//	b2Vec2 gravity(0.0f, 10.0f);
//	b2World world(gravity);
//
//	// Ground
//	b2BodyDef groundBodyDef;
//	groundBodyDef.position.Set(25, 37.5f);
//	b2Body* groundBody = world.CreateBody(&groundBodyDef);
//	b2PolygonShape groundBox;
//	groundBox.SetAsBox(25, 5);
//	groundBody->CreateFixture(&groundBox, 0);
//	sf::RectangleShape sfGround(sf::Vector2f(2 * metretoPixel(groundBox.m_vertices[2].x, scaler), 2 * metretoPixel(groundBox.m_vertices[2].y, 60)));
//	sfGround.setOrigin(sf::Vector2f(metretoPixel(groundBox.m_vertices[2].x, scaler), metretoPixel(groundBox.m_vertices[2].y, scaler)));
//	sfGround.setPosition(sf::Vector2f(metretoPixel(groundBody->GetPosition().x, scaler), metretoPixel(groundBody->GetPosition().y, scaler)));
//	sfGround.setFillColor(sf::Color::Green);
//
//	// Playable Character
//	// Square
//	b2BodyDef charAbBodyDef;
//	charAbBodyDef.type = b2_dynamicBody;
//	charAbBodyDef.position.Set(25, 6);
//	b2Body* charAbBody = world.CreateBody(&charAbBodyDef);
//	b2PolygonShape charAb;
//	charAb.SetAsBox(1.5f, 1.5f);
//	b2FixtureDef charAbBodyFixtureDef;
//	charAbBodyFixtureDef.shape = &charAb;
//	charAbBodyFixtureDef.density = 1;
//	charAbBodyFixtureDef.friction = 0.3f;
//	charAbBody->CreateFixture(&charAbBodyFixtureDef);
//	sf::RectangleShape sfCharAb(sf::Vector2f(metretoPixel(2 * charAb.m_vertices[2].x, scaler), metretoPixel(2 * charAb.m_vertices[2].y, scaler)));
//	sfCharAb.setOrigin(sf::Vector2f(metretoPixel(charAb.m_vertices[2].x, scaler), metretoPixel(charAb.m_vertices[2].y, scaler)));
//	sfCharAb.setPosition(sf::Vector2f(metretoPixel(charAbBody->GetPosition().x, scaler), metretoPixel(charAbBody->GetPosition().y, scaler)));
//	sfCharAb.setFillColor(sf::Color::Red);
//	// Circle
//	b2CircleShape charHead;
//	charHead.m_radius = 1;
//	charHead.m_p = b2Vec2(0, -2);
//	b2FixtureDef charHeadFixtureDef;
//	charHeadFixtureDef.shape = &charHead;
//	charHeadFixtureDef.density = 1;
//	charHeadFixtureDef.friction = 0.3f;
//	charAbBody->CreateFixture(&charHeadFixtureDef);
//	sf::CircleShape sfCharHead(metretoPixel(charHead.m_radius, scaler));
//	sfCharHead.setOrigin(sf::Vector2f(metretoPixel(charHead.m_radius, scaler), metretoPixel(charHead.m_radius, scaler)));
//	sfCharHead.setPosition(sf::Vector2f(metretoPixel(charHead.m_p.x, scaler), metretoPixel(charHead.m_p.y, scaler)));
//
//	// Another Body
//	b2BodyDef anotherBodyDef;
//	anotherBodyDef.type = b2_dynamicBody;
//	anotherBodyDef.position.Set(24, -5);
//	b2Body* anotherBody = world.CreateBody(&anotherBodyDef);
//	b2PolygonShape anotherBodyShape;
//	anotherBodyShape.SetAsBox(2, 1);
//	b2FixtureDef anotherBodyFixtureDef;
//	anotherBodyFixtureDef.shape = &anotherBodyShape;
//	anotherBodyFixtureDef.density = 1;
//	anotherBodyFixtureDef.friction = 0.3f;
//	anotherBody->CreateFixture(&anotherBodyFixtureDef);
//	sf::RectangleShape sfAnotherBody(sf::Vector2f(metretoPixel(2 * anotherBodyShape.m_vertices[2].x, scaler), metretoPixel(2 * anotherBodyShape.m_vertices[2].y, scaler)));
//	sfAnotherBody.setOrigin(sf::Vector2f(metretoPixel(anotherBodyShape.m_vertices[2].x, scaler), metretoPixel(anotherBodyShape.m_vertices[2].y, scaler)));
//	sfAnotherBody.setPosition(sf::Vector2f(metretoPixel(anotherBody->GetPosition().x, scaler), metretoPixel(anotherBody->GetPosition().y, scaler)));
//	sfAnotherBody.setFillColor(sf::Color::Blue);
//
//	// A Static Body
//	b2BodyDef staticBodyDef;
//	staticBodyDef.type = b2_staticBody;
//	staticBodyDef.position.Set(30, 30);
//	b2Body* staticBody = world.CreateBody(&staticBodyDef);
//	b2PolygonShape staticBodyShape;
//	staticBodyShape.SetAsBox(3, 3);
//	staticBody->CreateFixture(&staticBodyShape, 0);
//	sf::RectangleShape sfStaticBody(sf::Vector2f(metretoPixel(2 * staticBodyShape.m_vertices[2].x, scaler), metretoPixel(2 * staticBodyShape.m_vertices[2].y, scaler)));
//	sfStaticBody.setOrigin(sf::Vector2f(metretoPixel(staticBodyShape.m_vertices[2].x, scaler), metretoPixel(staticBodyShape.m_vertices[2].y, scaler)));
//	sfStaticBody.setPosition(sf::Vector2f(metretoPixel(staticBody->GetPosition().x, scaler), metretoPixel(staticBody->GetPosition().y, scaler)));
//	sfStaticBody.setFillColor(sf::Color::White);
//
//
//	bool jumping = false;
//
//	while (window.isOpen()) {
//		sf::Event event;
//		while (window.pollEvent(event)) {
//			if (event.type = sf::Event::Closed)
//				window.close();
//		}
//
//		// Physics
//		if (deltaTime.getElapsedTime().asSeconds() > timeStep) {
//
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//				charAbBody->ApplyForce(b2Vec2(-100, 0), charAbBody->GetWorldCenter(), true);
//			}
//			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//				charAbBody->ApplyForce(b2Vec2(100, 0), charAbBody->GetWorldCenter(), true);
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//				if (!jumping) {
//					charAbBody->ApplyLinearImpulse(b2Vec2(0, -100), charAbBody->GetWorldCenter(), true);
//					jumping = true;
//				}
//			}
//
//			if (charAbBody->GetLinearVelocity().y == 0) {
//				jumping = false;
//			}
//
//			world.Step(timeStep, velocityIterations, positionIterations);
//			deltaTime.restart();
//		}
//
//		// Draw
//		sfCharAb.setPosition(sf::Vector2f(metretoPixel(charAbBody->GetPosition().x, scaler), metretoPixel(charAbBody->GetPosition().y, scaler)));
//		sfCharAb.setRotation(RadToDeg(charAbBody->GetAngle()));
//		sfCharHead.setPosition(sf::Vector2f(metretoPixel(charAbBody->GetPosition().x + charHead.m_p.x, scaler), metretoPixel(charAbBody->GetPosition().y + charHead.m_p.y, scaler)));
//		float charHeadX = sinf(charAbBody->GetAngle()) * charHead.m_p.Length();
//		float charHeadY = cosf(charAbBody->GetAngle() + 3.14f) * charHead.m_p.Length();
//		sfCharHead.setPosition(sf::Vector2f(metretoPixel(charAbBody->GetPosition().x + charHeadX, scaler), metretoPixel(charAbBody->GetPosition().y + charHeadY, scaler)));
//		sfAnotherBody.setPosition(sf::Vector2f(metretoPixel(anotherBody->GetPosition().x, scaler), metretoPixel(anotherBody->GetPosition().y, scaler)));
//		
//		window.clear();
//		window.draw(sfGround);
//		window.draw(sfCharAb);
//		window.draw(sfCharHead);
//		window.draw(sfAnotherBody);
//		window.draw(sfStaticBody);
//		window.display();
//	}
//
//	// Cleanup
//	groundBody = nullptr;
//	charAbBody = nullptr;
//	anotherBody = nullptr;
//	staticBody = nullptr;
//
//	return 0;
//}
//
///*
//// Ground Body
//b2BodyDef groundBodyDef;
//groundBodyDef.position.Set(25, 25);
//
//b2Body* groundBody = world.CreateBody(&groundBodyDef);
//b2PolygonShape groundBox;
//groundBox.SetAsBox(30, 5);
//groundBody->CreateFixture(&groundBox, 0);
//sf::RectangleShape sfGround(sf::Vector2f(scaler * groundBox.m_vertices[2].x * 2, scaler * groundBox.m_vertices[2].y * 2));
////sf::RectangleShape sfGround(sf::Vector2f(scaler * 60, scaler * 10));
//sfGround.setOrigin(groundBox.m_vertices[2].x * scaler, groundBox.m_vertices[2].y * scaler);
//sfGround.setPosition(sf::Vector2f(metretoPixel(groundBody->GetPosition().x, scaler), metretoPixel(groundBody->GetPosition().y, scaler)));
////sfGround.setPosition(5, 5);
//sfGround.setFillColor(sf::Color::Green);
//
//// Square Body
//b2BodyDef squareBodyDef;
//squareBodyDef.type = b2_dynamicBody;
//squareBodyDef.position.Set(10, 0);
//squareBodyDef.angle = (3.14f / 3);
//b2Body* boxBody = world.CreateBody(&squareBodyDef);
//b2PolygonShape squareBox;
//squareBox.SetAsBox(2, 2);
//b2FixtureDef boxFixtureDef;
//boxFixtureDef.shape = &squareBox;
//boxFixtureDef.density = 1;
//boxFixtureDef.friction = 0.3f;
//boxBody->CreateFixture(&boxFixtureDef);
//sf::RectangleShape sfBox(sf::Vector2f(squareBox.m_vertices[2].x * scaler * 2, squareBox.m_vertices[2].y * scaler * 2));
////sf::RectangleShape sfBox(sf::Vector2f(4 * scaler, 4 * scaler)
//sfBox.setOrigin(scaler * squareBox.m_vertices[2].x, scaler * squareBox.m_vertices[2].y);
//sfBox.setPosition(sf::Vector2f(boxBody->GetPosition().x * scaler, boxBody->GetPosition().y * scaler));
//sfBox.setFillColor(sf::Color::Red);
//
//while (window.isOpen()) {
//sf::Event event;
//while (window.pollEvent(event)) {
//if (event.type == sf::Event::Closed)
//window.close();
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//rect.move(-5, 0);
//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//rect.move(5, 0);
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//rect.move(0, -5);
//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//rect.move(0, 5);
//}
//
//if (deltaTime.getElapsedTime().asSeconds() > timeStep) {
//deltaTime.restart();
//world.Step(timeStep, velocityIterations, positionIterations);
////sfBoxBody.setPosition(sf::Vector2f(scaler * body->GetPosition().x, scaler * body->GetPosition().y));
////b2Vec2 position = body->GetPosition();
////float32 angle = body->GetAngle();
////printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
//b2Vec2 p = boxBody->GetPosition();
//float32 a = boxBody->GetAngle();
//printf("Box X: %4.2f, Box Y: %4.2f, Box Size X: %4.2f, Box Size Y: %4.2f\n", boxBody->GetAngle(), boxBody->GetPosition().y, squareBox.m_vertices[2].x, squareBox.m_vertices[2].y);
//printf("Ground X: %4.2f, Ground Y: %4.2f, Ground Size X: %4.2f, Ground Size Y: %4.2f\n", groundBody->GetPosition().x, groundBody->GetPosition().y, groundBox.m_vertices[2].x, groundBox.m_vertices[2].y);
//}
//
//sfBox.setPosition(sf::Vector2f(scaler * boxBody->GetPosition().x, scaler * boxBody->GetPosition().y));
//sfBox.setRotation(boxBody->GetAngle() * (180 / 3.14));
//
//window.clear();
//window.draw(sfGround);
//window.draw(sfBox);
////window.draw(rect);
////window.draw(sfBoxBody);
//window.display();
//}
//
//groundBody = nullptr;
//boxBody = nullptr;
//*/
