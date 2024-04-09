#ifndef PIPE_H
#define PIPE_H
#include "Object.h"
class Pipe : public Object {
	private:
	public:
		Pipe(Vector2f spawnPoint, Vector2f velocity, unsigned int tickSpeed) : Object('p', spawnPoint, velocity, Vector2f(0, 0), tickSpeed) {}
		float x() { return objState.position.x; }
};

#endif