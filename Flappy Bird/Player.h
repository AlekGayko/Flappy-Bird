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
		float gravity = 2000;
	public:
		Player() : Player(60) {}
		Player(unsigned int tickSpeed) {
			bird = Bird(Vector2f(100, 100), gravity, tickSpeed);
		}
		void jump() {
			if (!isDead) {
				bird.jump();
			}
		}
		void increment() {
			if (isDead) {
				//bird.sprites[0].setRotation(max(-20, -ticksSinceDeath));
				//ticksSinceDeath++;
			}
			bird.increment();
			bird.rotateAnimation();
		}
		Sprite sprite() { return bird.getSprites()[0]; }
		bool dead() { return isDead; }
		float x() { return bird.objState.position.x; }
};

#endif