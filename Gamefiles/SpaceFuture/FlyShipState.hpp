#ifndef FLYSHIPSTATE_HPP
#define FLYSHIPSTATE_HPP

#include <SFML/Graphics.hpp>
#include "../Engine/UIElement.hpp"
#include "../Engine/Gamestate.hpp"

#include "GameObject.hpp"
#include "NPCShip.hpp"
#include "Playership.hpp"
#include "Planet.hpp"
#include "Camera.hpp"

class FlyShipState : public Gamestate
{
    public:
        FlyShipState();
        ~FlyShipState();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        //TODO: Do this with smart pointers!
        GameObject  *playership;
        GameObject  *earth;

        Camera      camera;
};

#endif // FLYSHIPSTATE_HPP
