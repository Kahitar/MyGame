#ifndef PLAYERSHIP_HPP
#define PLAYERSHIP_HPP

#include <Spaceship.hpp>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ObjectTime.hpp"

class Playership : public Spaceship
{
    public:
        Playership();
        ~Playership();

        void handle(Framework &frmwrk);

    private:
        void EvaluatePressedKeys(Framework &frmwrk);

//        ObjectTime mClock;
//
//        sf::Image ShipImage;
//        sf::Texture ShipTexture;
//        sf::Sprite ShipSprite;
};

#endif // PLAYERSHIP_HPP
