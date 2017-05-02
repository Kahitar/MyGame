#ifndef MATH_HPP
#define MATH_HPP


class math
{
    public:
        math();
        ~math();

        static float round(float value, int decimalPlaces = 2);
        static float CalculateDilationFactor(float velocity);
        static float CalculateDistanceInLightyears(double distance);
        static float CalculateDistanceInLightMinutes(double distance);

        // Constants //
        static const float pi; // Kreiszahl
        static const float c;  // Lichtgeschwindigkeit

    private:
};

#endif // MATH_HPP
