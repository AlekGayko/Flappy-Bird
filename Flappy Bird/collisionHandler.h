#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include <SFML/Graphics.hpp>
#include "PipeController.h"
#include "FloorController.h"
#include "Player.h"

class CollisionHandler {
	public:
		bool initCollision(PipeController& pipeController, FloorController& floors, Player& player) {
			bool collisionOccurred = false;
			//does player collide with any pipes?
			for (size_t it = 0; it < pipeController.pipes.size(); it++) {
				if (isCollision(player.bird, pipeController.pipes[it])) {
					collisionOccurred = true;
				}
			}
			//does player collide with floor?
			for (size_t it = 0; it < floors.floors.size(); it++) {
				if (isCollision(player.bird, floors.floors[it])) {
					collisionOccurred = true;
				}
			}

			collisionOccurred = false;
		}
		bool isCollision(Object& obj1, Object& obj2) {
			if (obj1.getSprite().getGlobalBounds().intersects(obj2.getSprite().getGlobalBounds())) {
				reactionPhysics(obj1, obj2);
				return true;
			}
		}
		void reactionPhysics(Object& obj1, Object& obj2) {
			if (obj2.getType() == 'p') {
				obj1.objState.velocity.x *= -1;
			}
			else if (obj2.getType() == 'f') {
				obj1.objState.velocity.y *= -1;
			}
			else {
				cerr << "incorrect collision" << endl;
			}
		}
};

#endif