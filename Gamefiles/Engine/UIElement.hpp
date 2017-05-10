#ifndef UIElement_HPP
#define UIElement_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Slider.hpp"
#include "TextBox.hpp"

class Framework;

class UIElement
{
    public:
        UIElement();
        ~UIElement();

        void addButton (sf::Vector2f pos, sf::Vector2f Size, std::string Name, std::string Text);
        void addSlider (sf::Vector2f pos, sf::Vector2f Size, std::string Name, 
                        std::string Text, std::string unit = "");
        void addTextBox(std::string name, std::string text = "I am a Textbox!", sf::Vector2f position = sf::Vector2f(0,0),
                        std::string FontPath = "assets\\fonts\\PAPYRUS.TTF", int borderThickness = 1,
                        sf::Color fillColor = sf::Color::Black, sf::Color outlineColor = sf::Color::Black);

        Button&  getButton (std::string ButtonName);
        Slider&  getSlider (std::string SliderName);
        TextBox& getTextBox(std::string TextBoxName);

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

    private:
        std::map<std::string, std::shared_ptr<Button>>  Buttons;
        std::map<std::string, std::shared_ptr<Slider>>  Sliders;
        std::map<std::string, std::shared_ptr<TextBox>> TextBoxes;

};

#endif // UIElement_HPP
