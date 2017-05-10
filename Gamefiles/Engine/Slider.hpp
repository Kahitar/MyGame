#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextBox.hpp"

class Framework;

class Slider
{
    public:
        Slider(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Size = sf::Vector2f(200, 50), 
               std::string text = "This is a Slider", std::string unit = "");
        ~Slider();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);

        ///////////Setter///////////
        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f Size);
        void setValue(int SliderValue);
        void setNumberOfPositions(int NumberOfPositions);
        void setSliderText(std::string text, std::string unit);
        void setUnitText(std::string unit);
        void setMinMax(int min, int max);

        ///////////Getter///////////
        sf::Vector2f getPosition()  {return mPos;};
        sf::Vector2f getSize()      {return mSize;};
        bool getMouseOnSlider()     {return mMouseOnSlider;};
        int getSliderValue();

    private:
        void ChangeSliderPosition(float newX);

        sf::Vector2f    mPos;
        sf::Vector2f    mSize;

        sf::RectangleShape  mSliderRect;
        sf::RectangleShape  mSliderBar;

        std::string     mSliderString;
        std::string     mSliderUnit;
        TextBox         mSliderText;

        float   mRectWidth;

        bool    mMouseOnSlider;
        bool    mClicked;

        int     mNumberOfPositions;
        int     mSliderPosition;
        int     mSliderValue;
        float   mStepSize;
        int     mMin;
        int     mMax;
};

#endif // SLIDER_HPP
