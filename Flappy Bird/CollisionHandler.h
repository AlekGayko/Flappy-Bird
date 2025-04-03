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
					player.isDead = true;
					collisionOccurred = true;
				}
			}
			//does player collide with floor?
			for (size_t it = 0; it < floors.floors.size(); it++) {
				if (isCollision(player.bird, floors.floors[it])) {
					player.isDead = true;
					collisionOccurred = true;
				}
			}
			return collisionOccurred;
		}
		bool isCollision(Object& obj1, Object& obj2) {
			for (size_t it = 0; it < obj2.sprites.size(); it++) {
				if (obj1.getSprites()[0].getGlobalBounds().intersects(obj2.getSprites()[it].getGlobalBounds())) {
					reactionPhysics(obj1, obj2);
					return true;
				}
			}
			return false;
		}
		void reactionPhysics(Object& obj1, Object& obj2) {
			if (obj2.getType() == 'p') {
				obj1.objState.velocity.x = obj2.objState.velocity.x;
				obj1.objState.velocity.y = obj1.objState.velocity.y < 0 && obj1.objState.position.y <= obj2.objState.position.y + 300 ? -obj1.objState.velocity.y : obj1.objState.velocity.y;
			}
			else if (obj2.getType() == 'f') {
				obj1.objState.velocity.x = obj2.objState.velocity.x;
				obj1.objState.position.y = obj2.objState.position.y - 1000;
				obj1.objState.velocity.y = 0;
				obj1.objState.acceleration.y = 0;
			}
			else {
				cerr << "incorrect collision" << endl;
			}
		}
};

#endif