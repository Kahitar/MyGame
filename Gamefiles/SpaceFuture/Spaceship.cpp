#include <sstream>
#include <string>

#include "../Engine/Framework.hpp"
#include "../Engine/ResourceManager.hpp"
#include "Spaceship.hpp"
#include "math.hpp"
#include "Variables.hpp"

Spaceship::Spaceship(std::string texturePath, sf::Vector2f position)
    :mName("Of course I still love you"),mVelocity(0),mMass(ResourceManager::getPlayershipMass()),
     mRelativisticMass(mMass),mForce(ResourceManager::getAcceleratingForce()),
     mAcceleratingInDirection(0),mGamePosition(position),mSpacePosition(position)
{
    //TODO: Load these from the ResourceManager
    ShipImage.loadFromFile(texturePath);
    ShipImage.createMaskFromColor(sf::Color::White);
    ShipTexture.loadFromImage(ShipImage);
    ShipSprite.setTexture(ShipTexture);
    ShipSprite.setPosition(position);
    // TODO: set the Center of the Sprite on mGamePosition (instead of the topleft corner)
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

    uielements.addTextBox("ShipMassTextbox", "Relativistic Mass: ");
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::update(Framework &frmwrk)
{
    CalculateNewVelocity(mAcceleratingInDirection*mForce);
    CalculateRelativisticMass();
    moveShip(frmwrk);
    
    mClock.setPosition(sf::Vector2f(mGamePosition.x,mGamePosition.y - 100));
    mClock.update(frmwrk, mVelocity);
    WriteStateVariables();

    std::stringstream ssMass;
    ssMass << "Relativistic Mass: " << mRelativisticMass;
    std::string sMass = ssMass.str();

    uielements.getTextBox("ShipMassTextbox").setText(sMass);
    uielements.getTextBox("ShipMassTextbox").setPosition(sf::Vector2f(mGamePosition.x,mGamePosition.y-140));

    uielements.update(frmwrk);
}

void Spaceship::moveShip(Framework &frmwrk)
{
    float dx = mVelocity*frmwrk.getFrameTime();
    mSpacePosition = sf::Vector2f(mSpacePosition.x + dx,mSpacePosition.y);

    // TODO: Use boundaries calculated on runtime depending on the relative
    // position to other objects in space
    if(mSpacePosition.x < 50000 && mSpacePosition.x > -50000) {
        mGamePosition = mSpacePosition;
    } else if (mSpacePosition.x >= 50000) {
        mGamePosition.x = 50000;
    } else {
        mGamePosition.x = -50000;
    }
    ShipSprite.setPosition(mGamePosition);
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
    float mVAsPercentageOfC = math::round(mVelocity / math::c, 3);

    mVelocityText.setPosition(mGamePosition.x,mGamePosition.y - 70);
    std::stringstream ssVelocity;

    if(mVAsPercentageOfC > 0.001) {
        ssVelocity << "v = " << mVAsPercentageOfC << " * c ";
    } else {
        ssVelocity << "v = " << round(mVelocity) << " m/s "; 
    }
    std::string sVelocity = ssVelocity.str();
    mVelocityText.setString(sVelocity);   

    // Position from origin
    float mPositionInLightminutes = math::round(math::CalculateDistanceInLightMinutes(mSpacePosition.x),5);

    mPositionText.setPosition(mGamePosition.x,mGamePosition.y - 40);
    std::stringstream ssPosition;

    if(mPositionInLightminutes < 0.001) {
        ssPosition << "d = " 
                   << round(mSpacePosition.x / 1000) 
                   << " km ";
    } else if (mPositionInLightminutes < 60) {
        ssPosition << "d = " 
                   << math::round(math::CalculateDistanceInLightMinutes(mSpacePosition.x),4) 
                   << " lm ";
    } else if (mPositionInLightminutes < 24*60) {
        ssPosition << "d = " 
                   << math::round(math::CalculateDistanceInLightMinutes(mSpacePosition.x)/24,2) 
                   << " ld ";
    } else if (mPositionInLightminutes < 365.25*24*60) {
        ssPosition << "d = " 
                   << math::round(math::CalculateDistanceInLightMinutes(mSpacePosition.x)/24/365.25,2) 
                   << " ly ";
    }
    
    std::string sPosition = ssPosition.str();
    mPositionText.setString(sPosition);
}

void Spaceship::CalculateRelativisticMass()
{
    mRelativisticMass = mMass * math::CalculateDilationFactor(mVelocity);
}

// Setter and Getter //

void Spaceship::setPosition(sf::Vector2f position)
{
    mSpacePosition = position;

    if(mSpacePosition.x < 50000 && mSpacePosition.x > -50000){
        mGamePosition = mSpacePosition;
    } else if (mSpacePosition.x >= 50000) {
        mGamePosition.x = 50000;
    } else {
        mGamePosition.x = -50000;
    }
    ShipSprite.setPosition(mGamePosition);
}

sf::Vector2f Spaceship::getCenter()
{
    float x = ShipSprite.getGlobalBounds().left + ShipSprite.getGlobalBounds().width/2;
    float y = ShipSprite.getGlobalBounds().top + ShipSprite.getGlobalBounds().height/2;

    return sf::Vector2f(x,y);
}