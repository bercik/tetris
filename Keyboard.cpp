#include "Keyboard.h"

Keyboard::Keyboard()
{
	this->up = new Key(sf::Keyboard::Up);
	this->down = new Key(sf::Keyboard::Down);
	this->left = new Key(sf::Keyboard::Left);
	this->right = new Key(sf::Keyboard::Right);
	this->enter = new Key(sf::Keyboard::Return);
	this->escape = new Key(sf::Keyboard::Escape);
}

Keyboard::~Keyboard()
{
	delete this->up;
	delete this->down;
	delete this->left;
	delete this->right;
	delete this->enter;
	delete this->escape;
}

void Keyboard::update(float deltaTime)
{
	up->update(deltaTime);
	down->update(deltaTime);
	left->update(deltaTime);
	right->update(deltaTime);
	enter->update(deltaTime);
	escape->update(deltaTime);
}
