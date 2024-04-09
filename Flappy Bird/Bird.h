#ifndef BIRD_H
#define BIRD_H
#include "Object.h"
class Bird : public Object {
	private:
		float gravity = -9.81;
	public:
		Bird() : Bird(Vector2f(100, 100), 60) {}
		Bird(Vector2f spawnPoint, unsigned tickSpeed) : Object('b', spawnPoint, Vector2f(-10, 0), Vector2f(0, gravity), tickSpeed) {}
		void jump() {
			objState.acceleration.y = 1000;
		}
};

#endif