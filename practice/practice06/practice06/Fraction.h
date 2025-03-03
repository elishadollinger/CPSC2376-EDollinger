/*
    Elisha Dollinger
    Practice06
    CPSC2376
    Spring 2025
 */

#pragma once//Includes the stream once
#include <iostream>

//Initializers
class Fraction
{
    private:
        int num;
        int den;
    public:
        /*I had to use GPT to figure out that I didn't need to use two constructors
         Instead, I just set the default constructor in the header instead of the cpp file*/
        Fraction(int num = 0, int den = 1) : num(num), den(den) {}
        int getNum() const;
        int getDen() const;
        void setNum(int n);
        void setDen(int d);
        void simplify();
        friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
        friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
        friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
        friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Fraction& lhs);
};
