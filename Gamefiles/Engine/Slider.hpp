#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Framework;

class Slider
{
    public:
        Slider(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Size = sf::Vector2f(200, 50));
        ~Slider();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

        ///////////Setter///////////
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f Size);
        void setValue(int multiplicatedValue);
        void setNumberOfPositions(int newNumber);
        void setMinMax(int min, int max);

        ///////////Getter///////////
        sf::Vector2f getPosition()  {return mPos;};
        sf::Vector2f getSize()      {return mSize;};
        int getSliderValue();

        bool getMouseOnSlider()     {return mMouseOnSlider;};

    private:
        void ChangeSliderPosition(float newX);

        sf::Vector2f    mPos;
        sf::Vector2f    mSize;

        sf::RectangleShape  mSliderRect;
        sf::RectangleShape  mSliderBar;

        float           mBarWidth;

        bool            mMouseOnSlider;
        bool            mClicked;

        int             mNumberOfPositions;
        int             mSliderValue;
        int             mValueMultiplicator;
        int             mMultiplicatedValue;
};

#endif // SLIDER_HPP
