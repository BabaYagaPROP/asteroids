#pragma once
#ifndef functions_h
#define functions_h

#include "spaceship.h"
const int windowWidth = 800, windowHeight = 600;

void wrapObjects(sf::RenderWindow &window,Spaceship& object, sf::Sprite &sprite);
void wrapObjects(sf::RenderWindow &window,Spaceship& object, sf::RectangleShape box);
void wrapObjects(sf::RenderWindow& window, Spaceship& object, sf::CircleShape shape);


#endif