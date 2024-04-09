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
	unsigned int tickSpeed = 75;
	window.setFramerateLimit(tickSpeed);
	GameManager manager = GameManager(tickSpeed);
	while (window.isOpen()) {
		manager.nextTick();
		manager.drawObjects(&window);
		if (manager.gameOver()) {
			window.close();
		}
	}
	return 0;
}