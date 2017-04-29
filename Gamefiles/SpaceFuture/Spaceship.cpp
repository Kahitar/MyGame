#include <sstream>
#include <string>

#include "Spaceship.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"

Spaceship::Spaceship(int y)
    :mName("Of course I still love you"),mVelocity(0),mPosition(0),mMass(10),mClock(y)
{
    font.loadFromFile("assets\\fonts\\PAPYRUS.TTF");
    mVelocityText.setFont(font);
    mVelocityText.setFillColor(sf::Color::Red);
    mVelocityText.setStyle(sf::Text::Bold);
    mVelocityText.setPosition(50,y);
    mVelocityText.setCharacterSize(24);
    mVelocityText.setStyle(sf::Text::Bold | sf::Text::Underlined);

    ShipImage.loadFromFile("assets\\textures\\star_trek_xi_enterprise_v1.png");
    ShipImage.createMaskFromColor(sf::Color::White);
    ShipTexture.loadFromImage(ShipImage);
    ShipSprite.setTexture(ShipTexture);
    ShipSprite.setPosition(500,500);
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::update(Framework &frmwrk, float force)
{
    mClock.update(frmwrk, mVelocity);

    double c = 299792458;
    double mVAsPercentegeOfC = mVelocity / c ;

    std::stringstream ssVelocity;
    ssVelocity << "v = " << mVAsPercentegeOfC << " * c ";
    std::string sVelocity = ssVelocity.str();

    mVelocityText.setString(sVelocity);

    CalculateNewVelocity(force);
}

void Spaceship::handle(Framework &frmwrk)
{

}

void Spaceship::render(Framework &frmwrk)
{
    mClock.render(frmwrk);
    frmwrk.spRenderWindow->draw(mVelocityText);
    frmwrk.spRenderWindow->draw(ShipSprite);
}

void Spaceship::CalculateNewVelocity(float force)
{
    float v_old = mVelocity;
    float v_new = v_old + (force/mMass)*mClock.getNextTimeStep();
    mVelocity = v_new;
}


