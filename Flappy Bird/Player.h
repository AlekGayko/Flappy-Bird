#ifndef PLAYER_H
#define PLAYER_H
#include "Bird.h"
class CollisionHandler;
class Player {
	friend CollisionHandler;
	private:
		Bird bird;
		bool isDead = false;
		int ticksSinceDeath = 0;
		float gravity = 2300;
	public:
		Player() : Player(60) {}
		Player(unsigned int tickSpeed) {
			bird = Bird(Vector2f(320, 250), gravity, tickSpeed);
		}
		void jump() {
			if (!isDead) {
				bird.jump();
			}
		}
		void increment() {
			bird.increment();
			bird.rotateAnimation();
		}
		Sprite sprite() { return bird.getSprites()[0]; }
		bool dead() { return isDead; }
		float x() { return bird.objState.position.x; }
		float y() { return bird.objState.position.y; }
};

#endif