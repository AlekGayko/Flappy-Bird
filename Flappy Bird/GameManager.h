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
		bool gameFinished = false;
		sf::Sprite scoresheet;
		sf::Texture scoresheetTexture;
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
			scoresheetTexture.loadFromFile("scoreSheet.png");
			scoresheet.setTexture(scoresheetTexture);
			scoresheet.setOrigin(scoresheet.getGlobalBounds().left + scoresheet.getGlobalBounds().width / 2.0f, scoresheet.getGlobalBounds().top + scoresheet.getGlobalBounds().height / 2.0f);
			scoresheet.setScale(8, 8);
			scoresheet.setPosition(320, 430);
		}
		void nextTick() {
			if (gameStarted) {
				pipeController.updatePipes();
				floors.update();
				player.increment();
				pipesPassed += pipeController.passedPipe(player.x(), player.y());
			}
			if (!gameFinished) {
				texts.update(gameOver(), gameStarted, pipesPassed);
				gameFinished = gameOver();
			}
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

			window->draw(player.sprite());

			for (Pipe pipe : pipes) {
				vector<Sprite> sprites = pipe.getSprites();
				for (Sprite sprite : sprites) {
					window->draw(sprite);
				}
			}

			for (Floor floor : floorObjects) {
				window->draw(floor.getSprites()[0]);
			}
			
			if (textVector.size() > 2 && gameStarted) {
				window->draw(scoresheet);
			}
			for (sf::Text text : textVector) {
				window->draw(text);
			}
		}
		bool gameOver() {
			return player.dead() || collider.initCollision(pipeController, floors, player);
		}
};

#endif