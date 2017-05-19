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

    mGlobalTimeStep = Framework::getFrameTime();
}

ObjectTime::~ObjectTime()
{
    ClockTextBox.deleteTextBox("ClockText");
}

void ObjectTime::reset(int newTime)
{
    mTime = newTime;
}

void ObjectTime::update(Framework &frmwrk, float velocity)
{
    updateTime(velocity);
    ClockTextBox.getTextBox("ClockText").setPosition(sf::Vector2f(mPosition.x,mPosition.y));

    float mTimeRounded = math::round(mTime,1);

    std::stringstream ssTime;
    ssTime << "t = " << mTimeRounded << " s";
    std::string sTime = ssTime.str();

    ClockTextBox.getTextBox("ClockText").setText(sTime);

    mGlobalTimeStep = Framework::getFrameTime();
}

void ObjectTime::render(Framework &frmwrk)
{
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
