#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PipeController.h"
#include "Player.h"
#include "FloorController.h"
#include "CollisionHandler.h"
#include "AssetManager.h"
#include "BackgroundController.h"

class GameManager {
	private:
		unsigned int tickSpeed = 0;
		unsigned int pipesPassed = 0;
		bool gameStarted = false;
		bool gameFinished = false;
		bool restart = false;
		bool quit = false;
		Player player;
		PipeController pipeController;
		FloorController floors;
		BackgroundController background;
		CollisionHandler collider;
		AssetManager assets = AssetManager();
	public:
		GameManager() : GameManager(60) {}
		GameManager(unsigned int tickSpeed) : tickSpeed(tickSpeed) {
			pipeController = PipeController(tickSpeed);
			player = Player(tickSpeed);
			floors = FloorController(tickSpeed);
		}
		void nextTick() {

			if (gameStarted) {
				background.update();
				pipeController.updatePipes();
				floors.update();
				player.increment();
				pipesPassed += pipeController.passedPipe(player.x(), player.y());
			}
			if (!gameFinished) {
				assets.update(gameOver(), gameStarted, pipesPassed);
				gameFinished = gameOver();
			}
		}
		void eventHandle(sf::Event event, sf::RenderWindow& window) {
			if (gameFinished && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				 string resultAction = assets.buttonClicked(window);
				 if (resultAction == "Quit") {
					 quit = true;
				 }
				 else if (resultAction == "Restart") {
					 restart = true;
				 }
			} else if ((event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)) {
				gameStarted = true;
				player.jump();
			}
		}
		void drawObjects(sf::RenderWindow& window) {
			background.draw(window);
			window.draw(player.sprite());
			pipeController.draw(window);
			floors.draw(window);
			//assets.drawAssets(window);
		}
		bool gameOver() {
			return gameFinished || player.dead() || collider.initCollision(pipeController, floors, player);
		}
		bool hasQuit() { return quit; }
		bool hasRestart() { return restart; }
};

#endif