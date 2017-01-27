#ifndef BUTTONMANAGER_HPP
#define BUTTONMANAGER_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Framework;

class ButtonManager
{
    public:
        ButtonManager();
        ~ButtonManager();

        void addButton(sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text);

        Button getButton(std::string ButtonName);

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        std::map<std::string, std::shared_ptr<Button>> Buttons;

};

#endif // BUTTONMANAGER_HPP
