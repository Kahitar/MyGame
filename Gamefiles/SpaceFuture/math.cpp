#include "math.hpp"
#include <cmath>

#include <iostream>

const float math::pi = 3.14159265359;
const float math::c = 299792458;

math::math()
{
    //ctor
}

math::~math()
{
    //dtor
}

float math::round(float value, int decimalPlaces)
{
    float divider = pow(10,decimalPlaces);
    return roundf(value * divider) / divider;
}

float math::CalculateDilationFactor(float velocity)
{
    return 1/sqrt(1 - velocity*velocity/(c*c));
}

float math::CalculateDistanceInLightyears(double distance)
{
    double year = 365.25*24*60*60;
    double lightyear = c * year;

    float lyDistance = distance / lightyear;

    return lyDistance;
}

float math::CalculateDistanceInLightMinutes(double distance)
{
    double minute = 60;
    double lightminute = c * minute;

    float lmDistance = distance / lightminute;

    return lmDistance;
}
