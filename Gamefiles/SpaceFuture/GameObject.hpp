#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class Framework;

class GameObject
{
public:
	virtual		 ~GameObject() {};
    virtual void update(Framework &frmwrk) = 0;
    virtual void handle(Framework &frmwrk) = 0;
    virtual void render(Framework &frmwrk) = 0;

    virtual sf::Vector2f getPosition() = 0;

    sf::Vector2f CalculateDistance(GameObject &otherObject);
};

#endif // GAMEOBJECT_HPP
