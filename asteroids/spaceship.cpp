#include "spaceship.h"


Spaceship::Spaceship(float newX, float newY, int newDX, int newDY, float newSize) {
	x = newX;
	y = newY;
	dx = newDX;
	dy = newDY;
	angleOfRotation = 0;
	velocity = 0;
	size = newSize;

};

void Spaceship::move(sf::Time dt)
{
	x += dx * dt.asSeconds();
	y += dy * dt.asSeconds();
}