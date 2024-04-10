#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PipeController.h"
#include "Player.h"
#include "FloorController.h"
#include "CollisionHandler.h"

class GameManager {
	private:
		unsigned int tickSpeed = 0;
		Player* player = nullptr;
		PipeController pipeController;
		FloorController floors;
	public:
		GameManager() : GameManager(60) {}
		GameManager(unsigned int tickSpeed) : tickSpeed(tickSpeed) {
			pipeController = PipeController(tickSpeed);
			player = new Player(tickSpeed);
			floors = FloorController(tickSpeed);
		}
		~GameManager() {
			delete player;
		}

		void nextTick() {
			pipeController.updatePipes();
			floors.update();
			player->increment();
			player->jump();
		}
		void drawObjects(sf::RenderWindow* window) {
			vector<Pipe> pipes = pipeController.allPipes();
			for (Pipe pipe : pipes) {
				window->draw(pipe.getSprite());
			}
			window->draw(player->sprite());
		}
		bool gameOver() {
			vector<Pipe> pipes = pipeController.allPipes();
			for (Pipe pipe : pipes) {
				if (player->sprite().getGlobalBounds().intersects(pipe.getSprite().getGlobalBounds())) {
					return true;
				}
			}
			return false;
		}
};

#endif