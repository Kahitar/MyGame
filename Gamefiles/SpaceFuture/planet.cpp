#include "../Engine/Framework.hpp"
#include "Planet.hpp"
#include "Variables.hpp"

Planet::Planet()
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

Planet::~Planet()
{
    //dtor
}

void Planet::update(Framework &frmwrk)
{

}

void Planet::handle(Framework &frmwrk)
{

}

void Planet::render(Framework &frmwrk)
{
    frmwrk.spRenderWindow->draw(mPlanetSprite);
}

// Getter and Setter //

sf::Vector2f Planet::getCenter()
{
    float x = mPlanetSprite.getGlobalBounds().left + mPlanetSprite.getGlobalBounds().width/2;
    float y = mPlanetSprite.getGlobalBounds().top + mPlanetSprite.getGlobalBounds().height/2;
    return sf::Vector2f(x, y);
}