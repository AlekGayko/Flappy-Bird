#ifndef FLOORCONTROLLER_H
#define FLOORCONTROLLER_H
#include "Floor.h"
#include <vector>

class FloorController {
	friend CollisionHandler;
	private:
		unsigned int tickSpeed = 0;
		unsigned int length = 0;
		vector<Floor> floors;
		Vector2f spawnPoint1;
		Vector2f spawnPoint2;
		int cutoffPoint = -100;
		void shuffle() {
			if (floors[0].x() < cutoffPoint) {
				floors.erase(floors.begin());
				floors.push_back(Floor(tickSpeed, spawnPoint2));
			}
		}
	public:
		FloorController() : FloorController(60) {}
		FloorController(unsigned int tickSpeed) : spawnPoint1(600, 700), spawnPoint2(spawnPoint1.x + 1400, spawnPoint1.y) {
			floors.push_back(Floor(tickSpeed, spawnPoint1));
			floors.push_back(Floor(tickSpeed, spawnPoint2));
			length = 2;
		}
		void update() {
			if (length > 0) {
				shuffle();
			}
			for (size_t it = 0; it < floors.size(); it++) {
				floors[it].increment();
			}
		}
		unsigned int size() { return length; }
};

#endif