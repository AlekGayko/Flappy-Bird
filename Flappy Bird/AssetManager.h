#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;

struct Button {
	int textSize = 60;
	sf::Text text;
	sf::Font font;
	sf::RectangleShape borderRect;
	sf::RectangleShape innerRect;
	sf::RectangleShape hitBox;
	sf::Color borderColor = sf::Color::Black;
	sf::Color innerColor = sf::Color::White;
	Button(std::string textString) {
		font.loadFromFile("Pixellettersfull-BnJ5.ttf");
		text.setFont(font);
		text.setString(textString);
	}
	void drawButton(sf::RenderWindow* window) {
		window->draw(borderRect);
		window->draw(innerRect);
		window->draw(text);
		window->draw(hitBox);
		return;
	}
};

class AssetManager {
	private:
		vector<Button> buttons;
	public:
};

#endif