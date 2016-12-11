#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Button
{
    public:
        Button(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Size = sf::Vector2f(200, 50), std::string text = "Button");
        ~Button();

        void update();
        void handle(std::shared_ptr<sf::Event> event);
        void render(std::shared_ptr<sf::RenderWindow> rw);

        ///////////Setter///////////
        void setText(std::string text);
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f Size);
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

        std::unique_ptr<sf::Texture> upTexture;
        std::unique_ptr<sf::Sprite>  upSpriteNotHovered;
        std::unique_ptr<sf::Sprite>  upSpriteHovered;

        float           TextureHeight;
        float           TextureWidth;

        bool            mMouseOnButton;
        bool            mClicked;
};

#endif // BUTTON_HPP
