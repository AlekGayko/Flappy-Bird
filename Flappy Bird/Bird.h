#ifndef BIRD_H
#define BIRD_H
#include "Object.h"
class Player;
class Bird : public Object {
	friend Player;
	private:
	public:
		Bird() : Bird(Vector2f(100, 100), 100, 60) {}
		Bird(Vector2f spawnPoint, float gravity, unsigned tickSpeed) : Object('b', spawnPoint, Vector2f(0, 0), Vector2f(0, gravity), tickSpeed) {}
		void jump() {
			cout << "acceleration: " << objState.acceleration.x << " " << objState.acceleration.y << endl;
			objState.acceleration.y = -100000;
		}
};

#endif