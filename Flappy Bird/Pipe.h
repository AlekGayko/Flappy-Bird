#ifndef PIPE_H
#define PIPE_H
#include "Object.h"
class Pipe : public Object {
	private:
	public:
		Pipe(Vector2f spawnPoint, Vector2f velocity, unsigned short int tickSpeed, unsigned short int pipeGap) : Object('p', spawnPoint, velocity, Vector2f(0, 0), tickSpeed) {
			sprites.erase(sprites.begin());
			int pipeHeight = image.getSize().y;
			Sprite sprite1(image);
			Sprite sprite2(image);
			sprite1.setPosition(objState.position.x, objState.position.y - pipeGap - pipeHeight);
			sprite2.setPosition(objState.position.x, objState.position.y + pipeGap);
			sprites.push_back(sprite1);
			sprites.push_back(sprite2);
		}
		float x() {	return objState.position.x;	}

};

#endif