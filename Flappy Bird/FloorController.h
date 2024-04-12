#ifndef FLOORCONTROLLER_H
#define FLOORCONTROLLER_H
#include "Floor.h"
#include <vector>
class CollisionHandler;
class FloorController {
	friend CollisionHandler;
	private:
		unsigned int tickSpeed = 0;
		vector<Floor> floors;
		Vector2f spawnPoint1;
		Vector2f spawnPoint2;
		int cutoffPoint = -997;
		void shuffle() {
			if (floors[0].x() < cutoffPoint) {
				floors.erase(floors.begin());
			}
			if (floors.size() < 2) {
				floors.push_back(Floor(tickSpeed, spawnPoint2));
			}
		}
	public:
		FloorController() : FloorController(60) {}
		FloorController(unsigned int tickSpeed) : spawnPoint1(0, 780), tickSpeed(tickSpeed) {
			spawnPoint2 = Vector2f(spawnPoint1.x - cutoffPoint, spawnPoint1.y);
			floors.push_back(Floor(tickSpeed, spawnPoint1));
			floors.push_back(Floor(tickSpeed, spawnPoint2));
		}
		void update() {
			shuffle();
			for (size_t it = 0; it < floors.size(); it++) {
				floors[it].increment();
			}
		}
		unsigned int size() { return floors.size(); }
		void draw(RenderWindow& window) {
			for (Floor floor : floors) {
				window.draw(floor.getSprites()[0]);
			}
		}
};

#endif