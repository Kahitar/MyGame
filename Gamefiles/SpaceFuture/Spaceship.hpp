#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/UIElement.hpp"
#include "ObjectTime.hpp"

class Framework;

class Spaceship
{
    public:
        Spaceship(std::string texturePath, sf::Vector2f position);
        ~Spaceship();

        // Setter //
        void setName(std::string name)      {mName = name;};
        void setVelocity(float velocity)    {mVelocity = velocity;};
        void setMass(float mass)            {mMass = mass;};
        void setPosition(sf::Vector2f position)    {mPosition = position;ShipSprite.setPosition(position);};

        // Getter //
        std::string getName() {return mName;};
        float getVelovity()   {return mVelocity;};
        float getMass()       {return mMass;};
        sf::Vector2f getPosition()   {return mPosition;};

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    protected:
        void CalculateNewVelocity(double force);
        void CalculateRelativisticMass();

        void WriteStateVariables();

        std::string mName;
        float mVelocity;
        float mMass; //inertial mass
        float mRelativisticMass; //relativistic mass
        long double mForce;
        int mAcceleratingInDirection; // -1 = left; 1 = right; 0 = not accelerating

        sf::Vector2f mPosition;

        ObjectTime mClock;

        sf::Font font;
        sf::Text mVelocityText;
        sf::Text mPositionText;

        sf::Image ShipImage;
        sf::Texture ShipTexture;
        sf::Sprite ShipSprite;

        UIElement uielements;
};

#endif // SPACESHIP_HPP
