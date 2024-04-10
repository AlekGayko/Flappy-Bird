#ifndef PIPECONTROLLER_H
#define PIPECONTROLLER_H
#include "Pipe.h"
#include <vector>

using namespace std;

class PipeController {
	private:
		vector<Pipe> pipes;
		unsigned long long int ticks = 0;
		unsigned int tickSpeed = 0;
		unsigned int length = 0;
		Vector2f spawnPoint;
		Vector2f pipeVelocity;
		float cutoffPoint = -100;
	public:
		PipeController() : PipeController(60) {}
		PipeController(unsigned int tickSpeed) : tickSpeed(tickSpeed), spawnPoint(400, 100), pipeVelocity(0, 0) {}
		void createPipe() { length++;  pipes.push_back(Pipe(spawnPoint, pipeVelocity, tickSpeed)); }
		void destroyPipe() { cout << "pipe deleted-----------" << endl; pipes.erase(pipes.begin()); }
		unsigned int size() { return length; }
		bool isPipeOutOfBounds() {
			return !pipes.empty() && pipes.front().x() < cutoffPoint;
		}
		void incrementPipes() {
			for (size_t it = 0; it < pipes.size(); it++) {
				pipes[it].increment();
			}
			return;
		}
		void updatePipes() {
			incrementPipes();
			if (isPipeOutOfBounds() && length > 0) {
				destroyPipe();
			}
			if (length < 5 && ticks % tickSpeed == 0) {
				createPipe();
			}
			ticks++;
			return;
		}
		vector<Pipe> allPipes() {
			return pipes;
		}
};

#endif