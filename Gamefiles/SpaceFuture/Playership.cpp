#include <sstream>
#include <string>
#include "Playership.hpp"

#include "Spaceship.hpp"
#include "Framework.hpp"

Playership::Playership(std::string texturePath, sf::Vector2f position)
    :Spaceship(texturePath, position)
{
    ShipSprite.setScale(0.1,0.1);

    mClock.setPosition(sf::Vector2f(300,100));

    Buttons.addButton(sf::Vector2f(250,100),sf::Vector2f(60,28),"TimeResetButton","Reset");
    Buttons.addButton(sf::Vector2f(250,130),sf::Vector2f(60,28),"VelocityResetButton","Reset");
}

Playership::~Playership()
{
    //dtor
}

void Playership::update(Framework &frmwrk)
{
    Spaceship::update(frmwrk);

    Buttons.update(frmwrk);
    Buttons.getButton("TimeResetButton").setPosition(sf::Vector2f(mPosition.x-70,mPosition.y-100));
    Buttons.getButton("VelocityResetButton").setPosition(sf::Vector2f(mPosition.x-70,mPosition.y-70));
}

void Playership::handle(Framework &frmwrk)
{
    Spaceship::handle(frmwrk);

    Buttons.handle(frmwrk);
    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && frmwrk.spMainEvent->mouseButton.button == sf::Mouse::Left)
    {
        if(Buttons.getButton("TimeResetButton").getMouseOnButton()){
            mClock.reset();
        }else if(Buttons.getButton("VelocityResetButton").getMouseOnButton()){
            mVelocity = 0;
        }
    }

    EvaluatePressedKeys(frmwrk);
}

void Playership::render(Framework &frmwrk)
{
    Spaceship::render(frmwrk);

    Buttons.render(frmwrk);
}

void Playership::EvaluatePressedKeys(Framework &frmwrk)
{
    //Keyboard Key pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mAcceleratingInDirection = -1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mAcceleratingInDirection = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mAcceleratingInDirection = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        setPosition(sf::Vector2f(500,300));
        setVelocity(0);
    }
}
