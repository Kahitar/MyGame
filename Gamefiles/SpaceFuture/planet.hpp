#ifndef PLANET_HPP
#define PLANET_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ObjectTime.hpp"

class Framework;

class planet
{
    public:
        planet();
        ~planet();

        // Setter //
        void setName(std::string name) {mName = name;};

        // Getter //
        std::string getName() {return mName;};

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);
    protected:
        std::string mName;

        sf::Texture mPlanetTexture;
        sf::Sprite  mPlanetSprite;

        ObjectTime mClock;
};

#endif // PLANET_HPP
