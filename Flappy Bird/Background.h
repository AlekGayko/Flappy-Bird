#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Object.h"
#include <vector>

class Background : public Object {
	private:
	public:
		Background(unsigned int tickSpeed, Vector2f spawnPoint) : Object('b', spawnPoint, Vector2f(-25, 0), Vector2f(0, 0), tickSpeed) {
			sf::Sprite sprite;
			image.loadFromFile("longBackground.png");
			sprite.setTexture(image);
			sprite.setPosition(objState.position.x, objState.position.y);
			sprites.push_back(sprite);
		}
};

#endif