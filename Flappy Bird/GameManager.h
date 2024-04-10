#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PipeController.h"
#include "Player.h"
#include "FloorController.h"
#include "CollisionHandler.h"

class GameManager {
	private:
		unsigned int tickSpeed = 0;
		Player player;
		PipeController pipeController;
		FloorController floors;
		CollisionHandler collider;
	public:
		GameManager() : GameManager(60) {}
		GameManager(unsigned int tickSpeed) : tickSpeed(tickSpeed) {
			pipeController = PipeController(tickSpeed);
			player = Player(tickSpeed);
			floors = FloorController(tickSpeed);
		}
		void nextTick() {
			pipeController.updatePipes();
			floors.update();
			player.increment();
		}
		void playerMove(sf::Event event) {
			if ((event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)) {
				player.jump();
			}
		}
		void drawObjects(sf::RenderWindow* window) {
			vector<Pipe> pipes = pipeController.allPipes();
			vector<Floor> floorObjects = floors.getFloors();
			for (Pipe pipe : pipes) {
				window->draw(pipe.getSprite());
			}
			for (Floor floor : floorObjects) {
				window->draw(floor.getSprite());
			}
			window->draw(player.sprite());
		}
		bool gameOver() {
			return collider.initCollision(pipeController, floors, player);
		}
};

#endif