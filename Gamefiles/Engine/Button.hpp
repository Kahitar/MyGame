#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "UIObject.hpp"

class Framework;

class Button : public UIObject
{
    public:
        Button(){};
        Button(sf::Vector2f pos = sf::Vector2f(0, 0), 
               sf::Vector2f Size = sf::Vector2f(200, 50), 
               std::string text = "Button"
               );
        ~Button();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

        ///////////Setter///////////
        void setScale(float x, float y);
        void setText(std::string text);
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f size);
        void setColor(sf::Color color);

        ///////////Getter///////////

    protected:

    private:
        sf::Text        mText;
        sf::Font        mFont;

        std::shared_ptr<sf::Texture> upTexture;
        std::shared_ptr<sf::Sprite>  upSpriteNotHovered;
        std::shared_ptr<sf::Sprite>  upSpriteHovered;

        float           TextureHeight;
        float           TextureWidth;
};

#endif // BUTTON_HPP
