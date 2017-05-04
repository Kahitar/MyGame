#include "Slider.hpp"
#include "Framework.hpp"

#include <string>
#include <sstream>
#include <cmath>

Slider::Slider(sf::Vector2f pos, sf::Vector2f Size)
    :mMouseOnSlider(false),mClicked(false),mNumberOfPositions(10),mSliderValue(0),mValueMultiplicator(1)
{
    mSliderBar.setFillColor(sf::Color(128, 128, 200));
    mSliderBar.setOutlineThickness(1);
    mSliderBar.setOutlineColor(sf::Color::Black);

    mSliderRect.setFillColor(sf::Color::Blue);
    mSliderRect.setOutlineThickness(1);
    mSliderRect.setOutlineColor(sf::Color::Black);

    setSize(Size);
    setPosition(pos);
    setValue(10);
}

Slider::~Slider()
{
    //dtor
}

void Slider::update(Framework &frmwrk)
{
    if(mClicked){
        ChangeSliderPosition(frmwrk.getTransformedMousePosition().x);
    }
}

void Slider::handle(Framework &frmwrk)
{
    std::shared_ptr<sf::Event> event = frmwrk.spMainEvent;

    sf::Vector2f MouseWorldPos = frmwrk.getTransformedMousePosition();

    if(MouseWorldPos.x > mPos.x
        && MouseWorldPos.y > mPos.y
        && MouseWorldPos.x < mPos.x + mSize.x
        && MouseWorldPos.y < mPos.y + mSize.y)
    {
        mMouseOnSlider = true;
    } else{
        mMouseOnSlider = false;
    }

    if(event->type == sf::Event::MouseButtonPressed && mMouseOnSlider)
        mClicked = true;
    else if(event->type == sf::Event::MouseButtonReleased)
        mClicked = false;
}

void Slider::render(Framework &frmwrk)
{
    std::stringstream ssSliderText;
    ssSliderText << "Accelerating Force: " << mMultiplicatedValue;

    mSliderText.setText(ssSliderText.str());
    mSliderText.setPosition(sf::Vector2f(mPos.x - mSliderText.getGlobalBounds().width - 0.15*mSliderBar.getGlobalBounds().width, mPos.y));

    mSliderText.render(frmwrk);

    frmwrk.spRenderWindow->draw(mSliderBar);
    frmwrk.spRenderWindow->draw(mSliderRect);
}

void Slider::ChangeSliderPosition(float MouseX)
{
    float left = 0;
    float right = 1;
    float newX = 0;

    float PosWidth = (mSize.x - mBarWidth) / (mNumberOfPositions - 1);

    for(int i = 0; i < mNumberOfPositions; i++){
        left = mPos.x + i*PosWidth;
        right = mPos.x + (i+1)*PosWidth;

        if(MouseX >= left && MouseX < right) {
            newX = left;
            mSliderValue = i;
        }
        else if (MouseX < mPos.x){
            newX = mPos.x;
            mSliderValue = 0;
        }
        else if (MouseX > mPos.x + mSize.x - mBarWidth){
            newX = mPos.x + mSize.x - mBarWidth;
            mSliderValue = mNumberOfPositions - 1;
        }
    }

    mMultiplicatedValue = mSliderValue * mValueMultiplicator;
    mSliderRect.setPosition(sf::Vector2f(newX, mPos.y));
}

///////////Setter///////////
void Slider::setPosition(sf::Vector2f pos)
{
    mPos = pos;
    mSliderBar.setPosition(mPos.x, mPos.y + mSize.y/2 - mSize.y * 0.2 / 2);
    mSliderRect.setPosition(mPos);
}

void Slider::setSize(sf::Vector2f Size)
{
    mSize = Size;
    mBarWidth = mSize.x * 0.05;
    mSliderBar.setSize(sf::Vector2f(mSize.x, mSize.y * 0.2));
    mSliderRect.setSize(sf::Vector2f(mBarWidth, mSize.y));
}

void Slider::setValue(int multiplicatedValue)
{
    mMultiplicatedValue = multiplicatedValue;
    mSliderValue = mMultiplicatedValue / mValueMultiplicator;

    float PosWidth = mSize.x / (mNumberOfPositions-1);
    float left = mPos.x + mSliderValue*PosWidth;
    float right = mPos.x + (mSliderValue+1)*PosWidth;
    float middle = (right + left - mBarWidth) / 2;

    float newX = middle -  mBarWidth/2;

    mSliderRect.setPosition(sf::Vector2f(newX, mPos.y));
}

void Slider::setNumberOfPositions(int newNumber)
{
    mNumberOfPositions = newNumber;
}

// Getter //
int Slider::getSliderValue()
{
    return mMultiplicatedValue;
}


void Slider::setMinMax(int min, int max)
{
    mValueMultiplicator = round((max - min) / mNumberOfPositions);
    mMultiplicatedValue = mSliderValue*mValueMultiplicator;
}
