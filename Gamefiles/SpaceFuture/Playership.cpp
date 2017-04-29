#include <sstream>
#include <string>
#include "Playership.hpp"

#include "Spaceship.hpp"
#include "Framework.hpp"

Playership::Playership()
{
//    font.loadFromFile("assets\\fonts\\PAPYRUS.TTF");
//    mVelocityText.setFont(font);
//    mVelocityText.setFillColor(sf::Color::Red);
//    mVelocityText.setStyle(sf::Text::Bold);
//    mVelocityText.setPosition(50,100);
//    mVelocityText.setCharacterSize(24);
//    mVelocityText.setStyle(sf::Text::Bold | sf::Text::Underlined);

    //TODO: Load these from the ResourceManager
    ShipImage.loadFromFile("assets\\textures\\star_trek_xi_enterprise_v1.png");
    ShipImage.createMaskFromColor(sf::Color::White);
    ShipTexture.loadFromImage(ShipImage);
    ShipSprite.setTexture(ShipTexture,true);
    ShipSprite.setPosition(500,300);
    ShipSprite.setScale(0.1,0.1);

    mClock.setPosition(sf::Vector2f(300,100));
}

Playership::~Playership()
{
    //dtor
}

void Playership::handle(Framework &frmwrk)
{
    EvaluatePressedKeys(frmwrk);
}

void Playership::EvaluatePressedKeys(Framework &frmwrk)
{
    //Keyboard Key pressed
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mForce = -1000;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mForce = 1000;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&
       !sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&
       !sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&
       !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mForce = 0;
    }
}
