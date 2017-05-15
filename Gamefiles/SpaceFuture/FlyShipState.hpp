#ifndef FLYSHIPSTATE_HPP
#define FLYSHIPSTATE_HPP

#include <SFML/Graphics.hpp>
#include "../Engine/UIElement.hpp"
#include "../Engine/Gamestate.hpp"

#include "NPCShip.hpp"
#include "Playership.hpp"
#include "planet.hpp"

class FlyShipState : public Gamestate
{
    public:
        FlyShipState();
        ~FlyShipState();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        //TODO: Use Polymorphism with (smart) pointers of type Spaceship
        //NPCShip    NPCShip;
        Playership playership;
        planet     earth;

        UIElement Buttons;

        sf::View    playerView;
};

#endif // FLYSHIPSTATE_HPP
