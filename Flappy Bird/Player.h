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
		float gravity = 1000;
	public:
		Player() : Player(60) {}
		Player(unsigned int tickSpeed) {
			bird = Bird(Vector2f(100, 100), gravity, tickSpeed);
		}
		void jump() {
			bird.jump();
		}
		void increment() {
			if (isDead) {
				bird.sprite.setRotation(max(-20, -ticksSinceDeath));
				ticksSinceDeath++;
			}
			bird.increment();
		}
		Sprite sprite() { return bird.getSprite(); }
};

#endif