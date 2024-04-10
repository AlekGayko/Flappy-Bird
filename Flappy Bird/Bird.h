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
			sprites[0].setScale(0.6f, 0.6f);
		}
		void jump() {
			objState.acceleration.y = -30000;
			objState.velocity.y = 0;
			startRotating = true;
			ticksSinceJump = 0;
		}
		void rotateAnimation() {
			if (startRotating) {
				ticksSinceJump++;
				
				if (sprites[0].getRotation() == 0) {
					sprites[0].setRotation(359);
				}
				else {
					sprites[0].setRotation(max(360 - maxRoationAngle, sprites[0].getRotation() - 1));
					if (ticksSinceJump > maxRoationAngle) {
						startRotating = false;
						ticksSinceJump = 0;
					}
				}
				
			}
			else {
				if (sprites[0].getRotation() > 0) {
					if (sprites[0].getRotation() == 359) {
						sprites[0].setRotation(0);
					}
					else {
						ticksSinceJump++;
						sprites[0].setRotation(sprites[0].getRotation() + 1);
					}
				}
			}
		}
};

#endif