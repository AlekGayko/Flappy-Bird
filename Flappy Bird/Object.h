#ifndef OBJECT_H
#define OBJECT_H
#include "ObjectState.h"
using namespace std;
class Object {
	protected:
		ObjectState objState;
		Texture image;
		unsigned int tickSpeed = 0;
		int usualAcceleration = 0;
	public:
		sf::Sprite sprite;
		Object(char type, Vector2f spawnPoint, Vector2f velocity, Vector2f acceleration, unsigned int tickSpeed) : objState(ObjectState(spawnPoint, velocity, acceleration)) {
			this->tickSpeed = tickSpeed;
			usualAcceleration = objState.acceleration.y;
			if (type == 'p') {
				image.loadFromFile("Pipe.png");
			}
			else if (type == 'b') {
				image.loadFromFile("Bird.png");
			}
			sprite.setTexture(image);
			sprite.setPosition(objState.position.x, objState.position.y);
		}
		void increment() {
			objState.position.x += objState.velocity.x / tickSpeed;
			objState.position.y += objState.velocity.y / tickSpeed;
			objState.velocity.x += objState.acceleration.x / tickSpeed;
			objState.velocity.y += objState.acceleration.y / tickSpeed;
			if (objState.acceleration.y > 0) {
				objState.acceleration.y = usualAcceleration;
			}
			sprite.setPosition(objState.position.x, objState.position.y);
		}
		Sprite sprite() { return sprite; }
};

#endif