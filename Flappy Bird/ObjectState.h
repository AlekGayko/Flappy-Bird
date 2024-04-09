#ifndef OBJECTSTATE_H
#define OBJECTSTATE_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

struct ObjectState {
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	ObjectState() : position(-100, -100), velocity(0, 0), acceleration(0, 0) {}
	ObjectState(Vector2f pos, Vector2f vel, Vector2f acc) : position(pos), velocity(vel), acceleration(acc) {}
};

#endif