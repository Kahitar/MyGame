#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "Framework.hpp"
#include "ObjectTime.hpp"

ObjectTime::ObjectTime()
    :mTime(0),mNextTimeStep(0),mPosition(0,0)
{
    font.loadFromFile("assets\\fonts\\PAPYRUS.TTF");
    mClockText.setFont(font);
    mClockText.setString("Hallo Welt");

    mClockText.setFillColor(sf::Color::Red);
    mClockText.setCharacterSize(24);
    mClockText.setStyle(sf::Text::Bold | sf::Text::Underlined);

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
    mClockText.setPosition(mPosition.x,mPosition.y);

    float mTimeRounded = roundf(mTime * 100) / 100;

    std::stringstream ssTime;
    ssTime << "t = " << mTimeRounded << " s";
    std::string sTime = ssTime.str();

    mClockText.setString(sTime);

    mGlobalTimeStep = Framework::getFrameTime();
}

void ObjectTime::render(Framework &frmwrk)
{
    frmwrk.spRenderWindow->draw(mClockText);
}

void ObjectTime::updateTime(float velocity)
{
    calculateNextTimeStep(velocity);
    mTime = mTime + mNextTimeStep;
}

void ObjectTime::calculateNextTimeStep(double v_local)
{
	double c = 299792458;
    double dt_global = mGlobalTimeStep;

    double dilationFactor = 1/sqrt(1 - v_local*v_local/(c*c));
    double dt_local = dt_global / dilationFactor;

    mNextTimeStep = dt_local;
}
