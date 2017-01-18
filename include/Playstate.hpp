#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <Gamestate.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "Button.hpp"


class Playstate : public Gamestate
{
    public:
        Playstate();
        ~Playstate();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
//        sf::View playerView(sf::FloatRect(200,200,200,200));

        sf::RectangleShape mRect;
        sf::Texture texture;
        sf::Sprite sprite;

        std::unique_ptr<Button> upMainMenuButton;

};

#endif // PLAYSTATE_HPP
