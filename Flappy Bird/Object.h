#ifndef OBJECT_H
#define OBJECT_H
#include "ObjectState.h"
using namespace std;

class CollisionHandler;

class Object {
	friend CollisionHandler;
	protected:
		vector<sf::Sprite> sprites;
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
		}
		void increment() {
			objState.position.x += objState.velocity.x / tickSpeed;
			objState.position.y += objState.velocity.y / tickSpeed;
			objState.velocity.x += objState.acceleration.x / tickSpeed;
			objState.velocity.y += objState.acceleration.y / tickSpeed;
			if (objState.acceleration.y < 0) {
				objState.acceleration.y = usualAcceleration;
			}
			for (size_t it = 0; it < sprites.size(); it++) {
				sprites[it].setPosition(sprites[it].getPosition().x + objState.velocity.x / tickSpeed, sprites[it].getPosition().y + objState.velocity.y / tickSpeed);
			}
			return;
		}
		vector<Sprite> getSprites() { 
			for (size_t it = 0; it < sprites.size(); it++) {
				sprites[it].setTexture(image);
			}
			return sprites;
		}
		char getType() { return type; }
		float x() { return objState.position.x; }
		float y() { return objState.position.y; }
};

#endif