#ifndef BIRD_H
#define BIRD_H
#include "Object.h"
class Player;
class CollisionHandler;
class Bird : public Object {
	friend Player;
	friend CollisionHandler;
	private:
		bool startRotating = false;
		int ticksSinceJump = 0;
		float maxRoationAngle = 30;
	public:
		Bird() : Bird(Vector2f(100, 100), 100, 60) {}
		Bird(Vector2f spawnPoint, float gravity, unsigned tickSpeed) : Object('b', spawnPoint, Vector2f(0, 0), Vector2f(0, gravity), tickSpeed) {
			float scalingFactor = 4;
			sprites[0].setScale(scalingFactor, scalingFactor);
		}
		void jump() {
			objState.acceleration.y = -45000;
			objState.velocity.y = 0;
			startRotating = true;
			ticksSinceJump = 0;
		}
		void rotateAnimation() {
			if (startRotating) {
				ticksSinceJump++;
				if (sprites[0].getRotation() >= 2 && sprites[0].getRotation() < 3 * maxRoationAngle) {
					sprites[0].setRotation(sprites[0].getRotation() - 2);
				} else if (sprites[0].getRotation() < 2) {
					sprites[0].setRotation(359);
				}
				else {
					sprites[0].setRotation(max(360 - maxRoationAngle, sprites[0].getRotation() - 2));
					if (ticksSinceJump > maxRoationAngle) {
						startRotating = false;
						ticksSinceJump = 0;
					}
				}
				
			}
			else {
				if (sprites[0].getRotation() < 2 * maxRoationAngle || sprites[0].getRotation() > 300) {
					if (sprites[0].getRotation() == 359) {
						sprites[0].setRotation(0);
					}
					else {
						ticksSinceJump++;
						sprites[0].setRotation(sprites[0].getRotation() + 2);
					}
				}
			}
		}
};

#endif