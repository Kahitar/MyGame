#include <sstream>
#include <string>

#include "Spaceship.hpp"
#include "Framework.hpp"
#include "ResourceManager.hpp"
#include "math.hpp"

Spaceship::Spaceship(std::string texturePath, sf::Vector2f position)
    :mName("Of course I still love you"),mVelocity(0),mMass(10),mRelativisticMass(mMass),mForce(ResourceManager::getAcceleratingForce()),
    mAcceleratingInDirection(0),mPosition(sf::Vector2f(0,0))
{
    //TODO: Load these from the ResourceManager
    ShipImage.loadFromFile(texturePath);
    ShipImage.createMaskFromColor(sf::Color::White);
    ShipTexture.loadFromImage(ShipImage);
    ShipSprite.setTexture(ShipTexture);
    ShipSprite.setPosition(position);
    ShipSprite.setScale(0.3,0.3);

    font.loadFromFile("assets\\fonts\\PAPYRUS.TTF");
    mVelocityText.setFont(font);
    mVelocityText.setFillColor(sf::Color::Red);
    mVelocityText.setStyle(sf::Text::Bold);
    mVelocityText.setPosition(50,150);
    mVelocityText.setCharacterSize(24);
    mVelocityText.setStyle(sf::Text::Bold);

    mPositionText.setFont(font);
    mPositionText.setFillColor(sf::Color::Red);
    mPositionText.setStyle(sf::Text::Bold);
    mPositionText.setPosition(20,150);
    mPositionText.setCharacterSize(24);
    mPositionText.setStyle(sf::Text::Bold);

    uielements.addTextBox("ShipMass", "Relativistic Mass: ");
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::update(Framework &frmwrk)
{
    CalculateNewVelocity(mAcceleratingInDirection*mForce);
    CalculateRelativisticMass();

    ShipSprite.move(mVelocity*frmwrk.getFrameTime(),0);
    mPosition = ShipSprite.getPosition();

    mClock.setPosition(sf::Vector2f(mPosition.x,mPosition.y - 100));
    mClock.update(frmwrk, mVelocity);
    WriteStateVariables();

    std::stringstream ssMass;
    ssMass << "Relativistic Mass: " << mRelativisticMass;
    std::string sMass = ssMass.str();

    uielements.getTextBox("ShipMass").setText(sMass);
    uielements.getTextBox("ShipMass").setPosition(sf::Vector2f(mPosition.x,mPosition.y-140));

    uielements.update(frmwrk);
}

void Spaceship::handle(Framework &frmwrk)
{
    uielements.handle(frmwrk);
}

void Spaceship::render(Framework &frmwrk)
{
    mClock.render(frmwrk);
    frmwrk.spRenderWindow->draw(mVelocityText);
    frmwrk.spRenderWindow->draw(mPositionText);
    frmwrk.spRenderWindow->draw(ShipSprite);

    uielements.render(frmwrk);
}

void Spaceship::CalculateNewVelocity(double force)
{
    float v_old = mVelocity;
    float v_new = v_old + (force/mRelativisticMass)*mClock.getNextTimeStep();
    mVelocity = v_new;
}

void Spaceship::WriteStateVariables()
{
    //TODO: Do this with the TextBox class
    // Velocity as function of c
    float mVAsPercentegeOfC = math::round(mVelocity / math::c,4);

    mVelocityText.setPosition(mPosition.x,mPosition.y-70);
    std::stringstream ssVelocity;
    ssVelocity << "v = " << mVAsPercentegeOfC << " * c ";
    std::string sVelocity = ssVelocity.str();
    mVelocityText.setString(sVelocity);

    // Position from origin
    mPositionText.setPosition(mPosition.x,mPosition.y - 40);
    std::stringstream ssPosition;
    ssPosition << "d = " << math::round(math::CalculateDistanceInLightMinutes(mPosition.x),5) << " lm ";
    std::string sPosition = ssPosition.str();
    mPositionText.setString(sPosition);
}

void Spaceship::CalculateRelativisticMass()
{
    mRelativisticMass = mMass * math::CalculateDilationFactor(mVelocity);
}
