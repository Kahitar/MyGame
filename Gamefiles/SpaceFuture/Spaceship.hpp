#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ObjectTime.hpp"

class Framework;

class Spaceship
{
    public:
        Spaceship(int y);
        ~Spaceship();

        // Setter //
        void setName(std::string name)      {mName = name;};
        void setVelocity(float velocity)    {mVelocity = velocity;};
        void setPosition(float position)    {mPosition = position;};
        void setMass(float mass)            {mMass = mass;};

        // Getter //
        std::string getName() {return mName;};
        float getVelovity()   {return mVelocity;};
        float getPosition()   {return mPosition;};
        float getMass()       {return mMass;};

        void update(Framework &frmwrk, float force);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        void CalculateNewVelocity(float force);

        std::string mName;
        float mVelocity;
        float mPosition;
        float mMass;

        ObjectTime mClock;

        sf::Font font;
        sf::Text mVelocityText;

        sf::Image ShipImage;
        sf::Texture ShipTexture;
        sf::Sprite ShipSprite;
};

#endif // SPACESHIP_HPP
