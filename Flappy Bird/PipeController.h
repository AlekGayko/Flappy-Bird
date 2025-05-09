#ifndef PIPECONTROLLER_H
#define PIPECONTROLLER_H
#include "Pipe.h"
#include <vector>
#include <random>

using namespace std;
class CollisionHandler;
class PipeController {
	friend CollisionHandler;
	private:
		vector<Pipe> pipes;
		unsigned long long int ticks = 0;
		unsigned short int tickSpeed = 0;
		unsigned short int spawnLine = 850;
		unsigned short int pipeGap = 110;
		unsigned int ticksSincePass = 0;
		Vector2f pipeVelocity;
		short int cutoffPoint = -100;
	public:
		PipeController() : PipeController(60) {}
		PipeController(unsigned int tickSpeed) : tickSpeed(tickSpeed), pipeVelocity(-200, 0) {}
		void createPipe() { 
			random_device rd;
			mt19937 gen(rd());
			uniform_real_distribution<> dis(double(pipeGap) / 2 + 100, 780 - double(pipeGap) / 2 - 100);
			pipes.push_back(Pipe(Vector2f(spawnLine, dis(gen)), pipeVelocity, tickSpeed, pipeGap));
		}
		void destroyPipe() { pipes.erase(pipes.begin()); }
		unsigned int size() { return pipes.size(); }
		bool isPipeOutOfBounds() {
			return !pipes.empty() && pipes[0].x() < cutoffPoint;
		}
		void incrementPipes() {
			for (size_t it = 0; it < pipes.size(); it++) {
				pipes[it].increment();
			}
			return;
		}
		void updatePipes() {
			ticksSincePass++;
			incrementPipes();
			if (isPipeOutOfBounds() && pipes.size() > 0) {
				destroyPipe();
			}
			if (pipes.size() < 5 && ticks % (tickSpeed * 2) == 0) {
				createPipe();
			}
			ticks++;
			return;
		}
		bool passedPipe(int xPos, int yPos) {
			int tolerance = 20;
			for (Pipe pipe : pipes) {
				if (abs(pipe.x() + pipe.getSprites()[0].getGlobalBounds().width / 2 - xPos) < tolerance && ticksSincePass / tickSpeed > 1) {
					ticksSincePass = 0;
					return true;
				}
			}
			return false;
		}
		void draw(RenderWindow& window) {
			for (Pipe pipe : pipes) {
				window.draw(pipe.getSprites()[0]);
				window.draw(pipe.getSprites()[1]);
			}
		}
};

#endif