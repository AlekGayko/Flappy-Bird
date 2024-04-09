#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameManager.h"
using namespace std;
using namespace sf;

int main() {
	sf::RenderWindow window(VideoMode(600, 800), "Flappy Bird", Style::Titlebar | Style::Close);
	sf::Vector2i mousePosition = Mouse::getPosition(window);
	sf::Event event;
	sf::Sprite background;
	sf::Texture backTexture;
	backTexture.loadFromFile("background.jpg");
	background.setTexture(backTexture);
	unsigned int tickSpeed = 75;
	window.setFramerateLimit(tickSpeed);
	GameManager manager = GameManager(tickSpeed);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.draw(background);
		manager.nextTick();
		manager.drawObjects(&window);
		if (manager.gameOver()) {
			//window.close();
		}
		window.display();
	}
	return 0;
}