#ifndef FLYSHIPSTATE_HPP
#define FLYSHIPSTATE_HPP

#include <SFML/Graphics.hpp>
#include "UIElement.hpp"
#include "Gamestate.hpp"

#include "Spaceship.hpp"
#include "Playership.hpp"

//#inlcude "planet"
//#inlcude "scale"

class FlyShipState : public Gamestate
{
    public:
        FlyShipState();
        ~FlyShipState();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        Spaceship  ship;
        Playership playership;
//        planet      earth;
//        scale       xscale;

        UIElement Buttons;

//        sf::View    playerView;
};

#endif // FLYSHIPSTATE_HPP
