#ifndef OBJECT_H
#define OBJECT_H
#include "ObjectState.h"
using namespace std;
class Object {
	protected:
		sf::Sprite sprite;
		ObjectState objState;
		Texture image;
		unsigned int tickSpeed = 0;
		float usualAcceleration = 0;
		char type;
	public:
		Object(char type, Vector2f spawnPoint, Vector2f velocity, Vector2f acceleration, unsigned int tickSpeed) : objState(ObjectState(spawnPoint, velocity, acceleration)) {
			this->tickSpeed = tickSpeed;
			usualAcceleration = objState.acceleration.y;
			this->type = type;
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
			if (type == 'p') {
				cout << objState.position.x << " " << objState.position.y << endl;
				cout << "delta x: " << objState.velocity.x / tickSpeed << endl;
			}
			objState.position.x += objState.velocity.x / tickSpeed;
			if (type == 'p') {
				cout << "after: ";
				cout << objState.position.x << " " << objState.position.y << endl;
				cout << "delta x: " << objState.velocity.x / tickSpeed << endl;
			}
			objState.position.y += objState.velocity.y / tickSpeed;
			objState.velocity.x += objState.acceleration.x / tickSpeed;
			objState.velocity.y += objState.acceleration.y / tickSpeed;
			if (objState.acceleration.y > 0) {
				objState.acceleration.y = usualAcceleration;
			}
			sprite.setPosition(objState.position.x, objState.position.y);
			return;
		}
		Sprite getSprite() { return sprite; }
};

#endif