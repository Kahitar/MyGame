#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "../Engine/Framework.hpp"
#include "ObjectTime.hpp"
#include "math.hpp"

int ObjectTime::mClockNr = 0;

ObjectTime::ObjectTime(std::string name)
    :mTime(0),mNextTimeStep(0),mPosition(0,0)
{
    mClockNr++;
    ClockName << name << "_" << mClockNr;
    uielements.addTextBox(ClockName.str());
    uielements.getTextBox(ClockName.str()).setFillColor(sf::Color::Transparent);
    uielements.getTextBox(ClockName.str()).setBorderThickness(0);

    mGlobalTimeStep = Framework::getFrameTime();
}

ObjectTime::~ObjectTime()
{
    uielements.deleteTextBox(ClockName.str());
    mClockNr--;
}

void ObjectTime::reset(int newTime)
{
    mTime = newTime;
}

void ObjectTime::update(Framework &frmwrk, float velocity)
{
    updateTime(velocity);
    uielements.getTextBox(ClockName.str()).setPosition(sf::Vector2f(mPosition.x,mPosition.y));

    float mTimeRounded = math::round(mTime,1);

    std::stringstream ssTime;
    ssTime << "t = " << mTimeRounded << " s";
    std::string sTime = ssTime.str();

    uielements.getTextBox(ClockName.str()).setText(sTime);

    mGlobalTimeStep = Framework::getFrameTime();
}

void ObjectTime::render(Framework &frmwrk)
{
    
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
