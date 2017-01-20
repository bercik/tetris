#include "Key.h"

Key::Key(sf::Keyboard::Key key)
{
	this->key = key;
	this->prev = false;
	this->current = false;
}

void Key::update(float deltaTime)
{
	prev = current;

	current = sf::Keyboard::isKeyPressed(key);

	if (current) {
		counter += deltaTime;
	} else {
		counter = 0;
	}
}

bool Key::isPressed()
{
	return current;
}

bool Key::isDown()
{
	return current && !prev;
}

float Key::getCounter()
{
	return counter;
}
