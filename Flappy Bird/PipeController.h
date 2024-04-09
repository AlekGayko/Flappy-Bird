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
		Vector2f spawnPoint;
		Vector2f pipeVelocity;
		float cutoffPoint = -100;
	public:
		PipeController() : PipeController(60) {}
		PipeController(unsigned int tickSpeed) : tickSpeed(tickSpeed), spawnPoint(100, 100), pipeVelocity(-100, 0) {}	
		void createPipe() { pipes.push_back(Pipe(spawnPoint, pipeVelocity, tickSpeed)); }
		void destroyPipe() { pipes.erase(pipes.begin()); }
		bool isPipeOutOfBounds() {
			return !pipes.empty() && pipes.front().x() < cutoffPoint;
		}
		void incrementPipes() {
			for (Pipe pipe : pipes) {
				pipe.increment();
			}
			return;
		}
		void updatePipes() {
			incrementPipes();
			if (isPipeOutOfBounds()) {
				destroyPipe();
			}
			if (ticks % tickSpeed == 0) {
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