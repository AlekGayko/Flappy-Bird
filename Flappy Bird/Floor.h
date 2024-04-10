#ifndef FLOOR_H
#define FLOOR_H
#include "Object.h"

class Floor : public Object {
	private:
	public:
		Floor() : Floor(60, Vector2f(600, 700)) {}
		Floor(unsigned int tickSpeed, Vector2f spawnPoint) : Object('f', spawnPoint, Vector2f(-150, 0), Vector2f(0, 0), tickSpeed) {
			cout << "floor width: " << sprites[0].getGlobalBounds().left << endl;
		}
		float x() { return objState.position.x; }
};

#endif