#ifndef UIElement_HPP
#define UIElement_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Slider.hpp"

class Framework;

class UIElement
{
    public:
        UIElement();
        ~UIElement();

        void addButton(sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text);
        void addSlider(sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text);

        Button getButton(std::string ButtonName);
        Slider getSlider(std::string SliderName);

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        std::map<std::string, std::shared_ptr<Button>> Buttons;
        std::map<std::string, std::shared_ptr<Slider>> Sliders;

};

#endif // UIElement_HPP
