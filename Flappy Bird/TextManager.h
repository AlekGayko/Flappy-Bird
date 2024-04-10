#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
using namespace std;
class TextManager {
	private:
		sf::Font font;
		sf::Text pipeCounter;
		sf::Text gameOver;
		sf::Text ScoreLabel;
		sf::Text startDirections;
		std::string scoreString = "0";
		bool isGameOver = false;
		bool gameStarted = false;
		int textSize = 50;
	public:
		TextManager() {
			font.loadFromFile("Pixellettersfull-BnJ5.ttf");
			initSetup(pipeCounter);
			initSetup(gameOver);
			initSetup(ScoreLabel);
			initSetup(startDirections);

			pipeCounter.setString(scoreString);
			gameOver.setString("Game Over");
			ScoreLabel.setString("Score");
			startDirections.setString("Press LMB or Space");

			setOrigin(pipeCounter);
			setOrigin(gameOver);
			setOrigin(ScoreLabel);
			setOrigin(startDirections);

			pipeCounter.setPosition(320, 250);
			gameOver.setPosition(320, 350);
			ScoreLabel.setPosition(320, 425);
			startDirections.setPosition(320, 425);
		}
		void initSetup(sf::Text& text) {
			text.setFont(font);
			text.setCharacterSize(textSize);
		}
		void setOrigin(sf::Text& text) {
			text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
		}
		void update(bool isGameOver, bool gameStarted, int pipesPassed) {
			this->isGameOver = isGameOver;
			this->gameStarted = gameStarted;
			if (!isGameOver) {
				pipeCounter.setString(to_string(pipesPassed));
			}
		}
		vector<sf::Text> texts() {
			vector<sf::Text> textVector;
			if (isGameOver) {
				textVector.push_back(gameOver);
				textVector.push_back(ScoreLabel);
				pipeCounter.setPosition(ScoreLabel.getPosition().x, ScoreLabel.getPosition().y + 75);
				setOrigin(pipeCounter);
			}
			if (!gameStarted) {
				textVector.push_back(startDirections);
			}
			textVector.push_back(pipeCounter);
			return textVector;
		}
};

#endif