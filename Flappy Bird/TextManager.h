#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "TXTFetcher.h"

using namespace std;
class TextManager {
	private:
		sf::Font font;
		sf::Text pipeCounter;
		sf::Text bestScore;
		sf::Text gameOver;
		sf::Text scoreLabel;
		sf::Text bestScoreLabel;
		sf::Text startDirections;
		
		std::string scoreString = "0";
		TXTFetcher scoreHandler;
		bool isGameOver = false;
		bool gameStarted = false;
		int textSize = 60;
	public:
		TextManager() {
			font.loadFromFile("Pixellettersfull-BnJ5.ttf");
			initSetup(pipeCounter);
			initSetup(gameOver);
			initSetup(scoreLabel);
			initSetup(startDirections);
			initSetup(bestScore);
			initSetup(bestScoreLabel);

			pipeCounter.setString(scoreString);
			gameOver.setString("Game Over");
			scoreLabel.setString("Score");
			startDirections.setString("Press LMB or Space");
			bestScore.setString("0");
			bestScoreLabel.setString("Best Score");

			setOrigin(pipeCounter);
			setOrigin(gameOver);
			setOrigin(scoreLabel);
			setOrigin(startDirections);
			setOrigin(bestScore);
			setOrigin(bestScoreLabel);

			pipeCounter.setPosition(320, 150);
			gameOver.setPosition(320, 350);
			scoreLabel.setPosition(200, 425);
			bestScoreLabel.setPosition(440, 425);
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
		void draw(sf::RenderWindow& window) {
			if (isGameOver) {
				loadBestScore();
				drawText(window, gameOver);
				drawText(window, scoreLabel);
				drawText(window, bestScoreLabel);
				drawText(window, bestScore);
				pipeCounter.setPosition(scoreLabel.getPosition());
				pipeCounter.move(0, 75);
				setOrigin(pipeCounter);
			}
			if (!gameStarted) {
				drawText(window, startDirections);
			}
			drawText(window, pipeCounter);
		}
		void drawText(sf::RenderWindow& window, sf::Text text) {
			window.draw(backlight(text));
			window.draw(text);
		}
		sf::Text backlight(sf::Text text) {
			sf::Text shadow(text);
			shadow.setFillColor(sf::Color::Black);
			shadow.move(4, 4);
			return shadow;
		}
		void loadBestScore() {
			string bestScoreString = scoreHandler.getBestScore();
			string currentScore = pipeCounter.getString();
			if (stoi(bestScoreString) > stoi(currentScore)) {
				bestScore.setString(bestScoreString);
			}
			else { 
				bestScore.setString(currentScore);
				scoreHandler.setBestScore(stoi(currentScore));
			}
			setOrigin(bestScore);
			bestScore.setPosition(bestScoreLabel.getPosition());
			bestScore.move(0, 75);
			return;
		}
};

#endif