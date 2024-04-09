#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PipeController.h"
#include "Player.h"
class GameManager {
	private:
		unsigned int tickSpeed = 0;
		Player* player = nullptr;
		PipeController pipeController;
	public:
		GameManager() : GameManager(60) {}
		GameManager(unsigned int tickSpeed) : tickSpeed(tickSpeed) {
			pipeController = PipeController(tickSpeed);
			player = new Player(tickSpeed);
		}
		~GameManager() {
			delete player;
		}

		void nextTick() {
			pipeController.updatePipes();
		}
};

#endif