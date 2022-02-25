#pragma once
#include "functions.h"


void wrapObjects(sf::RenderWindow& window, Spaceship& object, sf::Sprite& sprite)
{
    //left
    
    //right
    
    //down

    //up
    
    if (object.x <= object.size )
    {
        sprite.setPosition(object.x + windowWidth , object.y);
        window.draw(sprite);
        object.x = (object.x + windowWidth);
        window.draw(sprite);

    }
    if (object.x >= windowWidth - object.size )
    {
        sprite.setPosition(object.x - windowWidth, object.y);
        window.draw(sprite);
        object.x = (object.x - windowWidth);
        window.draw(sprite);
    }
    if (object.y <= object.size )
    {
        sprite.setPosition(object.x, object.y + windowHeight);
        window.draw(sprite);
        object.y = (object.y + windowHeight);
        window.draw(sprite);
    }
    if (object.y >= windowHeight - object.size )
    {
        sprite.setPosition(object.x, object.y - windowHeight  );
        window.draw(sprite);
        object.y = ( object.y - windowHeight);
        window.draw(sprite);
    }
}

void wrapObjects(sf::RenderWindow& window, Spaceship& object, sf::RectangleShape box)
{
    //left
    
    //right
    
    //down
    
    //up
    
    if (object.x <= object.size)
    {
        box.setPosition(object.x + windowWidth, object.y);
        window.draw(box);
        object.x = (object.x + windowWidth);
        window.draw(box);

    }
    if (object.x >= windowWidth - object.size)
    {
        box.setPosition(object.x - windowWidth, object.y);
        window.draw(box);
        object.x = (object.x - windowWidth);
        window.draw(box);
    }
    if (object.y <= object.size)
    {
        box.setPosition(object.x, object.y + windowHeight);
        window.draw(box);
        object.y = (object.y + windowHeight);
        window.draw(box);
    }
    if (object.y >= windowHeight - object.size)
    {
        box.setPosition(object.x, object.y - windowHeight);
        window.draw(box);
        object.y = (object.y - windowHeight);
        window.draw(box);
    }
}
void wrapObjects(sf::RenderWindow& window, Spaceship& object, sf::CircleShape shape)
{
    //left

    //right

    //down

    //up

    if (object.x <= object.size)
    {
        shape.setPosition(object.x + windowWidth, object.y);
        window.draw(shape);
        object.x = (object.x + windowWidth);
        window.draw(shape);

    }
    if (object.x >= windowWidth - object.size)
    {
        shape.setPosition(object.x - windowWidth, object.y);
        window.draw(shape);
        object.x = (object.x - windowWidth);
        window.draw(shape);
    }
    if (object.y <= object.size)
    {
        shape.setPosition(object.x, object.y + windowHeight);
        window.draw(shape);
        object.y = (object.y + windowHeight);
        window.draw(shape);
    }
    if (object.y >= windowHeight - object.size)
    {
        shape.setPosition(object.x, object.y - windowHeight);
        window.draw(shape);
        object.y = (object.y - windowHeight);
        window.draw(shape);
    }
}

