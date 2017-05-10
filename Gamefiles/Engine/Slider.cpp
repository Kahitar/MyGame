#include "Slider.hpp"
#include "Framework.hpp"

#include <string>
#include <sstream>

#include "../SpaceFuture/math.hpp"

Slider::Slider(sf::Vector2f pos, sf::Vector2f Size, std::string text)
    :mMouseOnSlider(false),mClicked(false),mNumberOfPositions(10),mSliderPosition(0),
    mSliderValue(0),mStepSize(1),mMin(0),mMax(10)
{
    // Rectangle to move on
    mSliderBar.setFillColor(sf::Color(128, 128, 200));
    mSliderBar.setOutlineThickness(1);
    mSliderBar.setOutlineColor(sf::Color::Black);

    // Movable Rectangle
    mSliderRect.setFillColor(sf::Color::Blue);
    mSliderRect.setOutlineThickness(1);
    mSliderRect.setOutlineColor(sf::Color::Black);

    setSliderText(text);
    setSize(Size);
    setPosition(pos);
    // setValue(0);
}

Slider::~Slider()
{
    //dtor
}

void Slider::update(Framework &frmwrk)
{
    if(mClicked)
        ChangeSliderPosition(frmwrk.getTransformedMousePosition().x);
}

void Slider::handle(Framework &frmwrk)
{
    sf::Vector2f MouseWorldPos = frmwrk.getTransformedMousePosition();

    if(MouseWorldPos.x > mPos.x - mRectWidth
        && MouseWorldPos.y > mPos.y
        && MouseWorldPos.x < mPos.x + mSize.x + mRectWidth
        && MouseWorldPos.y < mPos.y + mSize.y)
    {
        mMouseOnSlider = true;
    } else{
        mMouseOnSlider = false;
    }

    if(frmwrk.spMainEvent->type == sf::Event::MouseButtonPressed && mMouseOnSlider)
        mClicked = true;
    else if(frmwrk.spMainEvent->type == sf::Event::MouseButtonReleased)
        mClicked = false;
}

void Slider::render(Framework &frmwrk)
{
    setSliderText(mSliderString);
    mSliderText.render(frmwrk);

    frmwrk.spRenderWindow->draw(mSliderBar);
    frmwrk.spRenderWindow->draw(mSliderRect);
}

void Slider::ChangeSliderPosition(float MouseX)
{
    float left = 0;
    float right = 1;
    float newX = 0;

    float PosWidth = mSize.x / (mNumberOfPositions - 1);

    // Checking if Mouse is somewhere in the slider space
    for(int i = 0; i < mNumberOfPositions; i++){
        left = mPos.x + i*PosWidth;
        right = mPos.x + (i+1)*PosWidth;

        if(MouseX >= left - PosWidth/2 && MouseX < right-PosWidth/2) {
            newX = left - mRectWidth/2;
            mSliderPosition = i;
        }
    }
    // Checking wether the Mouse isn't anywhere in the slider space
    if (MouseX < mPos.x){
        newX = mPos.x - mRectWidth/2;
        mSliderPosition = 0;
    }else if (MouseX >= mPos.x + mSize.x - PosWidth/2){
        newX = mPos.x + mSize.x - mRectWidth/2;
        mSliderPosition = mNumberOfPositions - 1;
    }

    mSliderValue = mMin + mSliderPosition*mStepSize;
    // std::cout << "MouseX: " << MouseX << std::endl;
    std::cout << "mSliderPosition: " << mSliderPosition << std::endl;
    mSliderRect.setPosition(sf::Vector2f(newX, mPos.y));
}

void Slider::setSliderText(std::string text)
{
    mSliderString = text;
    std::stringstream ssSliderText;
    ssSliderText << mSliderString << mSliderValue;

    mSliderText.setText(ssSliderText.str());
    mSliderText.setPosition(sf::Vector2f(mPos.x - mSliderText.getGlobalBounds().width - 0.15*mSliderBar.getGlobalBounds().width, mPos.y));
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
    mRectWidth = mSize.x * 0.05;
    mSliderBar.setSize(sf::Vector2f(mSize.x, mSize.y * 0.2));
    mSliderRect.setSize(sf::Vector2f(mRectWidth, mSize.y));
}

void Slider::setValue(int SliderValue)
{
    mSliderValue = SliderValue;
    mSliderPosition = round((mSliderValue - mMin) / mStepSize);
    std::cout << "Slider Position: " << mSliderPosition << std::endl;

    float PosWidth = mSize.x / (mNumberOfPositions-1);
    float left = mPos.x + mSliderPosition*PosWidth;
    float right = mPos.x + (mSliderPosition+1)*PosWidth;
    float middle = (right + left - mRectWidth) / 2;

    float newX = middle + mRectWidth/2;

    mSliderRect.setPosition(sf::Vector2f(newX, mPos.y));
}

void Slider::setNumberOfPositions(int NumberOfPositions)
{
    mNumberOfPositions = NumberOfPositions;
    setMinMax(mMin,mMax);
}

// Getter //
int Slider::getSliderValue()
{
    return mSliderValue;
}


void Slider::setMinMax(int min, int max)
{
    mMin = min;
    mMax = max;
    mStepSize = ((float)mMax - (float)mMin) / ((float)mNumberOfPositions-1);
    std::cout << "Step Size: " << mStepSize << std::endl;
    mSliderValue = mMin + mSliderPosition*mStepSize;
}
