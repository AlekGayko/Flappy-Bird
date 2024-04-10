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
			Sprite sprite;
			if (type == 'p') {
				image.loadFromFile("Pipe.PNG");
			}
			else if (type == 'b') {
				image.loadFromFile("Bird.PNG");
			}
			else if (type == 'f') {
				image.loadFromFile("floor.JPG");
			}
			sprite.setPosition(objState.position.x, objState.position.y);
			sprites.push_back(sprite);
		}
		void increment() {
			objState.position.x += objState.velocity.x / tickSpeed;
			objState.position.y += objState.velocity.y / tickSpeed;
			objState.velocity.x += objState.acceleration.x / tickSpeed;
			objState.velocity.y += objState.acceleration.y / tickSpeed;
			//objState.velocity.y = min(float(200), objState.velocity.y + objState.acceleration.y / tickSpeed);
			if (objState.acceleration.y < 0) {
				objState.acceleration.y = usualAcceleration;
			}
			for (size_t it = 0; it < sprites.size(); it++) {
				sprites[it].setPosition(objState.position.x, sprites[it].getPosition().y + objState.velocity.y / tickSpeed);
			}
			if (type == 't') {
				cout << sprites[0].getPosition().x << " " << sprites[0].getPosition().y << endl;
				cout << sprites[1].getPosition().x << " " << sprites[1].getPosition().y << endl;
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
};

#endif