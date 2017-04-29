#include "planet.hpp"
#include "Framework.hpp"

planet::planet()
    :mName("Planet XY")
{
    //TODO: Load these from the ResourceManager
    sf::Image PlanetImage;
    PlanetImage.loadFromFile("assets\\textures\\earth2.png");
    PlanetImage.createMaskFromColor(sf::Color::Black);
    mPlanetTexture.loadFromImage(PlanetImage);
    mPlanetSprite.setTexture(mPlanetTexture);
    mPlanetSprite.setPosition(-1500,-200);
//    mPlanetSprite.setScale(1.1,1.1);
}

planet::~planet()
{
    //dtor
}

void planet::update(Framework &frmwrk)
{

}

void planet::handle(Framework &frmwrk)
{

}

void planet::render(Framework &frmwrk)
{
    frmwrk.spRenderWindow->draw(mPlanetSprite);
}
