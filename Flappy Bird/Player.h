#ifndef PLAYER_H
#define PLAYER_H
#include "Bird.h"
class Player {
	private:
		Bird bird;
	public:
		Player() : Player(60) {}
		Player(unsigned int tickSpeed) {
			bird = Bird(Vector2f(100, 100), tickSpeed);
		}
		void jump() {
			bird.jump();
		}
};

#endif