#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include "TextManager.h"

using namespace std;

struct Button {
	int textSize = 60;
	int borderWidth = 8;
	sf::Text text;
	sf::Text shadowText;
	sf::Font font;
	sf::RectangleShape borderRect;
	sf::RectangleShape innerRect;
	sf::Color borderColor = sf::Color::Black;
	sf::Color innerColor = sf::Color(223, 200, 162, 255);
	sf::Vector2f position;
	sf::Vector2f innerRectSize;
	bool display = false;
	Button(std::string textString, sf::Vector2f position) : position(position) {
		font.loadFromFile("Pixellettersfull-BnJ5.ttf");
		text.setFont(font);
		text.setString(textString);
		text.setCharacterSize(textSize);
		setTextOrigin(text);
		text.setPosition(position);
		shadowText = backlight(text);
		innerRectSize = sf::Vector2f(text.getLocalBounds().width + 50, text.getLocalBounds().height * 1.5);
		innerRect.setSize(innerRectSize);
		borderRect.setSize(innerRectSize + sf::Vector2f(borderWidth, borderWidth));
		setRectOrigin(borderRect);
		setRectOrigin(innerRect);
		innerRect.setFillColor(innerColor);
		borderRect.setFillColor(borderColor);
		innerRect.setPosition(position);
		borderRect.setPosition(position);
	}
	void drawButton(sf::RenderWindow& window) {
		window.draw(borderRect);
		window.draw(innerRect);
		window.draw(shadowText);
		window.draw(text);
		return;
	}
	sf::Text backlight(sf::Text text) {
		sf::Text shadow(text);
		shadow.setFillColor(sf::Color::Black);
		shadow.move(4, 4);
		return shadow;
	}
	void setTextOrigin(sf::Text& text) {
		text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
	}
	void setRectOrigin(sf::RectangleShape& text) {
		text.setOrigin(text.getGlobalBounds().left + text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().top + text.getGlobalBounds().height / 2.0f - 3);
	}
	bool isClicked(sf::Vector2f mousePosition) {
		return borderRect.getGlobalBounds().contains(mousePosition);
	}
};

class AssetManager {
	private:
		vector<Button> buttons;
		Button restart = Button("Restart", sf::Vector2f(200, 575));
		Button quit = Button("Quit", sf::Vector2f(440, 575));
		sf::Sprite scoresheet;
		sf::Texture scoresheetTexture;
		TextManager texts = TextManager();
		bool gameStarted = false;
		bool gameOver = false;
	public:
		AssetManager() {
			scoresheetTexture.loadFromFile("scoreSheet.png");
			scoresheet.setTexture(scoresheetTexture);
			scoresheet.setOrigin(scoresheet.getGlobalBounds().left + scoresheet.getGlobalBounds().width / 2.0f, scoresheet.getGlobalBounds().top + scoresheet.getGlobalBounds().height / 2.0f);
			scoresheet.setScale(8, 10);
			scoresheet.setPosition(320, 470);

			buttons.push_back(restart);
			buttons.push_back(quit);
		}
		void update(bool isGameOver, bool gameStarted, int pipesPassed) {
			this->gameStarted = gameStarted;
			gameOver = isGameOver;
			if (gameOver) {
				for (size_t it = 0; it < buttons.size(); it++) {
					buttons[it].display = true;
				}
			}
			texts.update(isGameOver, gameStarted, pipesPassed);
			if (isGameOver) {
				for (size_t it = 0; it < buttons.size(); it++) {
					buttons[it].display = true;
				}
			}
		}
		void drawAssets(sf::RenderWindow& window) {
			if (gameOver) {
				window.draw(scoresheet);
			}
			for (Button button : buttons) {
				if (button.display == true) {
					button.drawButton(window);
				}
			}
			texts.draw(window);
		}
		string buttonClicked(sf::RenderWindow& window) {
			sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			for (Button button : buttons) {
				if (button.display == true && button.isClicked(mousePosition)) {
					return button.text.getString();
				}
			}
			return "";
		}
};

#endif