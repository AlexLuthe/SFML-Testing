#pragma once
#include "SFML\System.hpp"
#include "Box2D\Box2D.h"

	static sf::Vector2f B2toSFVector(b2Vec2 vec) {
		return sf::Vector2f(vec.x, vec.y);
	}

	static b2Vec2 SFtoB2Vector(sf::Vector2f vec) {
		return b2Vec2(vec.x, vec.y);
	}

	static float metretoPixel(float metres, float scaler) {
		return metres * scaler;
	}

	static float pixelToMetre(int pixels, float scaler) {
		return pixels / scaler;
	}

	static float DegToRad(float degrees) {
		return degrees * (3.14f / 180);
	}

	static float RadToDeg(float radians) {
		return radians * (180 / 3.14f);
	}