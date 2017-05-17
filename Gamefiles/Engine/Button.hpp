#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Framework;

class Button
{
    public:
        Button(){};
        Button(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Size = sf::Vector2f(200, 50), std::string text = "Button");
        ~Button();

        void update();
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

        ///////////Setter///////////
        void setText(std::string text);
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f size);
        void setColor(sf::Color color);

        ///////////Getter///////////
        sf::Vector2f getPosition()  {return mPos;};
        sf::Vector2f getSize()      {return mSize;};

        bool getMouseOnButton()     {return mMouseOnButton;};

    protected:

    private:
        sf::Text        mText;
        sf::Font        mFont;

        sf::Vector2f    mPos;
        sf::Vector2f    mSize;

        std::shared_ptr<sf::Texture> upTexture;
        std::shared_ptr<sf::Sprite>  upSpriteNotHovered;
        std::shared_ptr<sf::Sprite>  upSpriteHovered;

        float           TextureHeight;
        float           TextureWidth;

        bool            mMouseOnButton;
        bool            mClicked;
};

#endif // BUTTON_HPP
