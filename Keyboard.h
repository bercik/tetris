#pragma once

#include "Key.h"

#include <SFML/Window/Keyboard.hpp>

class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard();

	void update(float deltaTime);

	Key *up;
	Key *down;
	Key *left;
	Key *right;
	Key *enter;
	Key *escape;
};
