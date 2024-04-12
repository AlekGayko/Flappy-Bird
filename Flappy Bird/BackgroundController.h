#ifndef BACKGROUNDCONTROLLER_H
#define BACKGROUNDCONTROLLER_H
#include "Background.h"
#include <vector>

class BackgroundController {
	private:
		int cutoffPoint = -1428;
		unsigned int tickSpeed = 0;
		Vector2f spawn1;
		Vector2f spawn2;
		vector<Background> backgrounds;
		void shuffle() {
			if (backgrounds[0].x() < cutoffPoint) {
				backgrounds.erase(backgrounds.begin());
			}
			if (backgrounds.size() < 2) {
				backgrounds.push_back(Background(tickSpeed, spawn2));
			}
		}
	public:
		BackgroundController() : BackgroundController(60) {}
		BackgroundController(unsigned int tickSpeed) : tickSpeed(tickSpeed), spawn1(Vector2f(0, 0)) {
			spawn2 = Vector2f(spawn1.x - cutoffPoint, spawn1.y);
			backgrounds.push_back(Background(tickSpeed, spawn1));
			backgrounds.push_back(Background(tickSpeed, spawn2));
		}
		void update() {
			shuffle();
			for (size_t it = 0; it < backgrounds.size(); it++) {
				backgrounds[it].increment();
			}
		}
		unsigned int size() { return backgrounds.size(); }
		void draw(RenderWindow& window) {
			for (Background background : backgrounds) {
				window.draw(background.getSprites()[0]);
			}
		}
};

#endif