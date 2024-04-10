#ifndef PIPE_H
#define PIPE_H
#include "Object.h"
class Pipe : public Object {
	private:
	public:
		Pipe(Vector2f spawnPoint, Vector2f velocity, unsigned short int tickSpeed, unsigned short int pipeGap) : Object('p', spawnPoint, velocity, Vector2f(0, 0), tickSpeed) {
			sprites.erase(sprites.begin());
			Sprite sprite1(image);
			Sprite sprite2(image);
			float scalingFactor = 3.5;
			sprite1.setScale(scalingFactor, scalingFactor);
			sprite2.setScale(scalingFactor, scalingFactor);
			sprite1.setRotation(180);
			int pipeHeight = sprite1.getGlobalBounds().height;
			int pipeWidth = sprite1.getGlobalBounds().width;
			sprite1.setOrigin(sprite1.getGlobalBounds().left + pipeWidth, 0);
			sprite1.setPosition(objState.position.x + pipeWidth, objState.position.y - pipeGap);
			sprite2.setPosition(objState.position.x, objState.position.y + pipeGap);
			
			sprites.push_back(sprite1);
			sprites.push_back(sprite2);
		}
};

#endif