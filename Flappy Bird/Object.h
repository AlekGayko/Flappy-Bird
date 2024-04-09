#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjectState.h"
using namespace std;
class Object {
	protected:
		ObjectState objState;
		sf::Sprite sprite;
		unsigned int tickSpeed = 0;
	public:
		Object(Vector2f spawnPoint, Vector2f velocity, Vector2f acceleration, unsigned int tickSpeed) : objState(ObjectState(spawnPoint, velocity, acceleration)), tickSpeed(tickSpeed) {}
		void increment() {
			objState.position.x += objState.velocity.x / tickSpeed;
			objState.position.y += objState.velocity.y / tickSpeed;
			objState.velocity.x += objState.acceleration.x / tickSpeed;
			objState.velocity.y += objState.acceleration.y / tickSpeed;
			if (objState.acceleration.y > 0) {
				objState.acceleration.y = 0;
			}
		}
};

#endif