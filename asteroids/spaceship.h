

#ifndef spaceship_h
#define spaceship_h
#include <SFML/Graphics.hpp>



class Spaceship
{
public:
	Spaceship(float newX, float newY, int newDX, int newDY, float newSize);
	void move(sf::Time dt);

public:
	float x, y;
	int  dx, dy;
	float angleOfRotation;
	float velocity;
	float size;
	sf::Sprite sprite;
	sf::Texture texture;
	
};







#endif

