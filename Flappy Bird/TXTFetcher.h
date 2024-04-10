#ifndef TXTFETCHER_H
#define TXTFETCHER_H

#include <iostream>
#include <string>
#include <fstream>

struct TXTFetcher {
	std::string fileName = "BestScore.txt";
	std::string getBestScore() {
		std::ifstream file(fileName);
		std::string bestScore = "-1";
		if (file.is_open()) {
			std::getline(file, bestScore);
			file.close();
		}
		else {
			std::cerr << "couldn't open file" << std::endl;
		}
		return bestScore;
	}
	void setBestScore(int score) {
		std::ofstream file(fileName);
		if (file.is_open()) {
			file << std::to_string(score);
			file.close();
		}
		else {
			std::cerr << "couldn't open file" << std::endl;
		}
		return;
	}
};

#endif