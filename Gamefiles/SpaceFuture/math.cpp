#include "math.hpp"
#include <cmath>

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
    float divider = 10^decimalPlaces;
    return roundf(value * divider) / divider;
}