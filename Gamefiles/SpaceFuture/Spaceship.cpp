#include <sstream>
#include <string>

#include "../Engine/Framework.hpp"
#include "../Engine/ResourceManager.hpp"
#include "Spaceship.hpp"
#include "math.hpp"

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
    //uielements.addTextBox("VelocityText", "v = ");
    //uielements.addTextBox("PositionText", "x = ");
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
    int dx = mVelocity*frmwrk.getFrameTime();
    mSpacePosition = sf::Vector2f(mSpacePosition.x + dx,mSpacePosition.y);

    // TODO: Use boundaries calculated on runtime depending on the relative
    // position to other objects in space
    if(mSpacePosition.x < 50000 && mSpacePosition.x > -50000){
        mGamePosition = mSpacePosition;
    } else if (mSpacePosition.x >= 50000) {
        mGamePosition.x = 50000;
    } else {
        mGamePosition.x = -50000;
    }
    ShipSprite.setPosition(mGamePosition);


    std::cout << "x(ship_space) = " << mSpacePosition.x << std::endl;
    std::cout << "x(ship_game) = " << mGamePosition.x << std::endl;

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
    float mVAsPercentegeOfC = math::round(mVelocity / math::c, 4);

    mVelocityText.setPosition(mGamePosition.x,mGamePosition.y - 70);
    std::stringstream ssVelocity;
    ssVelocity << "v = " << mVAsPercentegeOfC << " * c ";
    std::string sVelocity = ssVelocity.str();
    mVelocityText.setString(sVelocity);

    // Position from origin
    mPositionText.setPosition(mGamePosition.x,mGamePosition.y - 40);
    std::stringstream ssPosition;
    ssPosition << "d = " << math::round(math::CalculateDistanceInLightMinutes(mSpacePosition.x),5) << " lm ";
    std::string sPosition = ssPosition.str();
    mPositionText.setString(sPosition);
}

void Spaceship::CalculateRelativisticMass()
{
    mRelativisticMass = mMass * math::CalculateDilationFactor(mVelocity);
}

// Setter //

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