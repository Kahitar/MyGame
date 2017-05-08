#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "../Engine/Framework.hpp"
#include "ObjectTime.hpp"
#include "math.hpp"

ObjectTime::ObjectTime()
    :mTime(0),mNextTimeStep(0),mPosition(0,0)
{
    ClockTextBox.addTextBox("ClockText");
    ClockTextBox.getTextBox("ClockText").setFillColor(sf::Color::Transparent);
    ClockTextBox.getTextBox("ClockText").setBorderThickness(0);

//    font.loadFromFile("assets\\fonts\\PAPYRUS.TTF");
//    mClockText.setFont(font);
//    mClockText.setString("Hallo Welt");

//    mClockText.setFillColor(sf::Color::Red);
//    mClockText.setCharacterSize(24);
//    mClockText.setStyle(sf::Text::Bold | sf::Text::Underlined);

    mGlobalTimeStep = Framework::getFrameTime();
}

ObjectTime::~ObjectTime()
{
    //dtor
}

void ObjectTime::reset(int newTime)
{
    mTime = newTime;
}

void ObjectTime::update(Framework &frmwrk, float velocity)
{
    updateTime(velocity);
//    mClockText.setPosition(mPosition.x,mPosition.y);
    ClockTextBox.getTextBox("ClockText").setPosition(sf::Vector2f(mPosition.x,mPosition.y));

    float mTimeRounded = math::round(mTime,1);

    std::stringstream ssTime;
    ssTime << "t = " << mTimeRounded << " s";
    std::string sTime = ssTime.str();

//    mClockText.setString(sTime);
    ClockTextBox.getTextBox("ClockText").setText(sTime);

    mGlobalTimeStep = Framework::getFrameTime();
}

void ObjectTime::render(Framework &frmwrk)
{
//    frmwrk.spRenderWindow->draw(mClockText);
    ClockTextBox.getTextBox("ClockText").render(frmwrk);
}

void ObjectTime::updateTime(float velocity)
{
    calculateNextTimeStep(velocity);
    mTime = mTime + mNextTimeStep;
}

void ObjectTime::calculateNextTimeStep(double v_local)
{
    double dt_global = mGlobalTimeStep;

    double dilationFactor = math::CalculateDilationFactor(v_local);
    double dt_local = dt_global / dilationFactor;

    mNextTimeStep = dt_local;
}

void ObjectTime::CalculateTimeInHours()
{

}
