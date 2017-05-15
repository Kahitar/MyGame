#include "../Engine/Framework.hpp"
#include "planet.hpp"
#include "Variables.hpp"

planet::planet()
    :mName("Planet XY")
{
    float TextureWidth = 1661;  // pxls
    int PlanetRadius = 6371000; // m

    float textureScale = (float)PlanetRadius / Variables::lengthScaleFactor / TextureWidth;

    float PlanetPixelRadius = PlanetRadius / (float)Variables::lengthScaleFactor;

    //TODO: Load these from the ResourceManager
    sf::Image PlanetImage;
    PlanetImage.loadFromFile("assets\\textures\\earth2.png");
    PlanetImage.createMaskFromColor(sf::Color::Black);
    mPlanetTexture.loadFromImage(PlanetImage);
    mPlanetSprite.setTexture(mPlanetTexture);
    mPlanetSprite.setPosition(-PlanetPixelRadius/2,-PlanetPixelRadius/2);
    mPlanetSprite.setScale(textureScale,textureScale);
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

// Getter and Setter //

sf::Vector2f planet::getPosition()
{
    return mPlanetSprite.getPosition();
}