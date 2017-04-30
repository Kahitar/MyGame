#ifndef MATH_HPP
#define MATH_HPP


class math
{
    public:
        math();
        ~math();

        static float round(float value, int decimalPlaces = 2);

        // Constants //
        static const float pi; // Kreiszahl
        static const float c;  // Lichtgeschwindigkeit

    private:

};

#endif // MATH_HPP
