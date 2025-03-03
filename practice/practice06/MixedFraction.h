#pragma once//Happens only once
#include "Fraction.h"//Includes the fraction header

class MixedFraction
{
    private:
        int whole;
        int numer;
        int denom;
    public:
        //This constructor initializes the fraction
        MixedFraction(int whole = 0, int numer = 0, int denom = 1) : whole(whole), numer(numer), denom(denom) {}
        //This constructor will correctly calculate a mixed fraction
        MixedFraction(const Fraction& frac);
        friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFrac);
};
