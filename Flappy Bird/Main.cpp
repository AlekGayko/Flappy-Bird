#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameManager.h"
using namespace std;
using namespace sf;

int main() {
	sf::RenderWindow window(VideoMode(640, 980), "Flappy Bird", Style::Titlebar | Style::Close);
	sf::Vector2i mousePosition = Mouse::getPosition(window);
	sf::Event event;
	sf::Sprite background;
	sf::Texture backTexture;
	backTexture.loadFromFile("background.jpg");
	background.setTexture(backTexture);
	unsigned int tickSpeed = 75;
	unsigned int ticksSinceDeath = 1;
	window.setFramerateLimit(tickSpeed);
	GameManager manager = GameManager(tickSpeed);
	while (window.isOpen()) {
		window.clear();
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			else {
				manager.playerMove(event);
			}
		}
		window.draw(background);
		manager.nextTick();
		manager.drawObjects(&window);
		if (manager.gameOver()) {
			ticksSinceDeath++;
			if (ticksSinceDeath % (tickSpeed * 4) == 0) {
				window.close();
			}
		}
		window.display();
	}
	return 0;
}