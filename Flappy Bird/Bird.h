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
		float maxRotationAngle = 30;
		int angularVelocity = 6;
	public:
		Bird() : Bird(Vector2f(100, 100), 100, 60) {}
		Bird(Vector2f spawnPoint, float gravity, unsigned tickSpeed) : Object('b', spawnPoint, Vector2f(0, 0), Vector2f(0, gravity), tickSpeed) {
			float scalingFactor = 4;
			sprites[0].setScale(scalingFactor, scalingFactor);
			sf::Vector2u size = image.getSize();
			sprites[0].setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
			sprites[0].setPosition(objState.position.x, objState.position.y);
			
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
				sprites[0].rotate(-angularVelocity);
				if (sprites[0].getRotation() < 360 - 1.5 * maxRotationAngle && sprites[0].getRotation() > 3 * maxRotationAngle) {
					startRotating = false;
					ticksSinceJump = 0;
				}			
			}
			else {
				if (sprites[0].getRotation() < 2 * maxRotationAngle || sprites[0].getRotation() > 300) {
					sprites[0].rotate(angularVelocity);
				}
			}
		}
};

#endif