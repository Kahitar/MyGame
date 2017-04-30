#include "NPCShip.hpp"

NPCShip::NPCShip(std::string texturePath, sf::Vector2f position)
    :Spaceship(texturePath,position)
{

}

NPCShip::~NPCShip()
{
    //dtor
}

void NPCShip::update(Framework &frmwrk)
{
    Spaceship::update(frmwrk);
}

void NPCShip::handle(Framework &frmwrk)
{
    Spaceship::handle(frmwrk);
}

void NPCShip::render(Framework &frmwrk)
{
    Spaceship::render(frmwrk);
}
