#include "Slider.hpp"
#include "Framework.hpp"

#include <string>
#include <sstream>

#include "../SpaceFuture/math.hpp"

Slider::Slider(sf::Vector2f pos, sf::Vector2f Size, std::string text, std::string unit)
    :mMouseOnSlider(false),mClicked(false),mNumberOfPositions(100),mSliderPosition(0),
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

    setSliderText(text, unit);
    setSize(Size);
    setPosition(pos);
}

Slider::~Slider()
{
    //dtor
}

void Slider::update(Framework &frmwrk)
{
    if(mClicked)
        ChangeSliderPosition(frmwrk.getTransformedMousePosition().x);

    setSliderText(mSliderString, mSliderUnit);
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
    mRectWidth = mSize.x * 0.05;
    mSliderBar.setSize(sf::Vector2f(mSize.x, mSize.y * 0.2));
    mSliderRect.setSize(sf::Vector2f(mRectWidth, mSize.y));
}

void Slider::setValue(int SliderValue)
{
    if(SliderValue < mMin){
        SliderValue = mMin;
        std::cout << "The Slider Value set was to low and was changed to the minimum value!" << std::endl;
    }
    else if(SliderValue > mMax){
        SliderValue = mMax;
        std::cout << "The Slider Value set was to high and was changed to the maximum value!" << std::endl;
    }
    mSliderValue = SliderValue;
    mSliderPosition = round((mSliderValue - mMin) / mStepSize);

    float PosWidth = mSize.x / (mNumberOfPositions - 1);
    float left = mPos.x + mSliderPosition*PosWidth;
    float newX = left - mRectWidth/2;

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

void Slider::setSliderText(std::string text, std::string unit)
{
    mSliderString = text;
    mSliderUnit = unit;
    std::stringstream ssSliderText;

    // Calculate the maximum size of the Textbox
    ssSliderText << mSliderString << mMax << " " << unit;
    mSliderText.setText(ssSliderText.str());
    int maxTextBoxSize = mSliderText.getGlobalBounds().width;
    ssSliderText.str("");

    // Set the actual slider Text
    ssSliderText << mSliderString << mSliderValue << " " << unit;
    mSliderText.setText(ssSliderText.str());
    mSliderText.setPosition(sf::Vector2f(mPos.x - maxTextBoxSize - 20, mPos.y));
}

void Slider::setUnitText(std::string unit)
{
    mSliderUnit = unit;
    setSliderText(mSliderString, mSliderUnit);
}

void Slider::setMinMax(int min, int max)
{
    mMin = min;
    mMax = max;
    mStepSize = ((float)mMax - (float)mMin) / ((float)mNumberOfPositions-1);

    // refresh the position of the sliderRect
    if(mSliderValue < mMin)
        setValue(mMin);
    else if(mSliderValue > mMax)
        setValue(mMax);
    else
        setValue(mSliderValue);
}
