#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameManager.h"

int main() {
	sf::RenderWindow window(VideoMode(640, 980), "Flappy Bird", Style::Titlebar | Style::Close);
	sf::Event event;
	unsigned int tickSpeed = 75;
	window.setFramerateLimit(tickSpeed);
	GameManager* manager = new GameManager(tickSpeed);
	while (window.isOpen()) {
		window.clear();
		if (manager->hasRestart()) {
			delete manager;
			manager = new GameManager(tickSpeed);
		}
		else if (manager->hasQuit()) {
			window.close();
		}
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			else {
				manager->eventHandle(event, window);
			}
		}
		manager->nextTick();
		manager->drawObjects(window);
		
		window.display();
	}
	delete manager;
	return 0;
}