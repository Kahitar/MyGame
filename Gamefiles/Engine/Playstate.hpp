#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <Gamestate.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "UIElement.hpp"
#include "Tileworld.hpp"


class Playstate : public Gamestate
{
    public:
        Playstate();
        ~Playstate();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        sf::View playerView;

        UIElement Buttons;

        float mMoveSpeed;

        Tileworld world1;

};

#endif // PLAYSTATE_HPP
