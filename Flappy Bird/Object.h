#ifndef OBJECT_H
#define OBJECT_H
#include "ObjectState.h"
using namespace std;

class CollisionHandler;

class Object {
	friend CollisionHandler;
	protected:
		
		sf::Sprite sprite;
		sf::Texture image;
		ObjectState objState;
		unsigned int tickSpeed = 0;
		float usualAcceleration = 0;
		char type;
	public:
		Object(char type, Vector2f spawnPoint, Vector2f velocity, Vector2f acceleration, unsigned int tickSpeed) : objState(ObjectState(spawnPoint, velocity, acceleration)) {
			this->tickSpeed = tickSpeed;
			usualAcceleration = objState.acceleration.y;
			this->type = type;
			if (type == 'p') {
				image.loadFromFile("Pipe.PNG");
			}
			else if (type == 'b') {
				image.loadFromFile("Bird.PNG");
			}
			else if (type == 'f') {
				image.loadFromFile("floor.JPG");
			}
			sprite.setTexture(image);
			sprite.setPosition(objState.position.x, objState.position.y);
		}
		void increment() {
			if (type == 'b') {
				cout << "position: " << objState.position.x << " " << objState.position.y << endl;
			}
			objState.position.x += objState.velocity.x / tickSpeed;
			objState.position.y += objState.velocity.y / tickSpeed;
			objState.velocity.x += objState.acceleration.x / tickSpeed;
			objState.velocity.y += objState.acceleration.y / tickSpeed;
			if (objState.acceleration.y < 0) {
				objState.acceleration.y = usualAcceleration;
			}
			sprite.setPosition(objState.position);
			return;
		}
		Sprite getSprite() { sprite.setTexture(image); return sprite; }
		char getType() { return type; }
};

#endif