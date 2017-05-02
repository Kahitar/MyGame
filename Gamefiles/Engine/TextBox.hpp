#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>

class Framework;

class TextBox
{
    public:
        TextBox(std::string text = "I am a Textbox!", sf::Vector2f position = sf::Vector2f(0,0), std::string FontPath = "assets\\fonts\\PAPYRUS.TTF",
                int borderThickness = 1, sf::Color fillColor = sf::Color::Black, sf::Color outlineColor = sf::Color::Transparent);
        ~TextBox();

        // Setter //
        void setText(std::string text);
        void setFont(std::string fontPath);
        void setPosition(sf::Vector2f position);
        void setBorderThickness(int borderThickness);
        void setFillColor(sf::Color fillColor);
        void setOutlineColor(sf::Color outlineColor);

        // Getter //
        std::string getText();
        sf::FloatRect getGlobalBounds();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);
    private:
        sf::Vector2f mPosition;
        sf::Font font;
        sf::Text mText;
//        sf::Vector2f mPosition;
        sf::RectangleShape mBorder;
};

#endif // TEXTBOX_HPP
