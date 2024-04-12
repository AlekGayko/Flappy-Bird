#ifndef FLOOR_H
#define FLOOR_H
#include "Object.h"

class Floor : public Object {
	private:
	public:
		Floor() : Floor(60, Vector2f(600, 700)) {}
		Floor(unsigned int tickSpeed, Vector2f spawnPoint) : Object('f', spawnPoint, Vector2f(-200, 0), Vector2f(0, 0), tickSpeed) {
			sf::Sprite sprite;
			image.loadFromFile("floor.jpg");
			sprite.setTexture(image);
			sprite.setPosition(objState.position.x, objState.position.y);
			sprites.push_back(sprite);
		}
		float x() { return objState.position.x; }
};

#endif