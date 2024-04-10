#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PipeController.h"
#include "Player.h"
#include "FloorController.h"
#include "CollisionHandler.h"
#include "TextManager.h"

class GameManager {
	private:
		unsigned int tickSpeed = 0;
		unsigned int pipesPassed = 0;
		bool gameStarted = false;
		Player player;
		PipeController pipeController;
		FloorController floors;
		CollisionHandler collider;
		TextManager texts;
	public:
		GameManager() : GameManager(60) {}
		GameManager(unsigned int tickSpeed) : tickSpeed(tickSpeed) {
			pipeController = PipeController(tickSpeed);
			player = Player(tickSpeed);
			floors = FloorController(tickSpeed);
		}
		void nextTick() {
			if (gameStarted) {
				pipeController.updatePipes();
				floors.update();
				player.increment();
				pipesPassed += pipeController.passedPipe(player.x());
			}
			texts.update(gameOver(), gameStarted, pipesPassed);
		}
		void playerMove(sf::Event event) {
			if ((event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)) {
				gameStarted = true;
				player.jump();
			}
		}
		void drawObjects(sf::RenderWindow* window) {
			vector<Pipe> pipes = pipeController.allPipes();
			vector<Floor> floorObjects = floors.getFloors();
			vector<sf::Text> textVector = texts.texts();
			for (Pipe pipe : pipes) {
				vector<Sprite> sprites = pipe.getSprites();
				for (Sprite sprite : sprites) {
					window->draw(sprite);
				}
			}
			for (Floor floor : floorObjects) {
				window->draw(floor.getSprites()[0]);
			}
			window->draw(player.sprite());
			for (sf::Text text : textVector) {
				window->draw(text);
			}
		}
		bool gameOver() {
			return collider.initCollision(pipeController, floors, player) || player.dead();
		}
};

#endif