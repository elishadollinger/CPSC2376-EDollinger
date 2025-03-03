//#include <iostream>
#include <limits>
#include <stdexcept>
#include <numeric>
#include "Fraction.h"

//Returns the numerator of the fraction
int Fraction::getNum() const
{
    return num;
}

//Returns the denominator of the fraction
int Fraction::getDen() const
{
    return den;
}

//Sets the numerator of the fraction
void Fraction::setNum(int n)
{
    num = n;
}

/*
    I had to use GPT to figure out how to throw an invalud argument
    Using a try catch loop later in the code, this will throw a statement that the user entered an invalid argument if they try to set the denominator to zero
    In turn, this will stop the user from entering a fraction in general
*/
void Fraction::setDen(int d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    den = d;
}

/*
    If the user enters a zero in the denominator, throw an invalid argument.
    Otherwise, use std::gcd to figure out the greatest common denominator
    Then, simplify by dividing by that denominator
    Finally, if the denominator is negative, make the numerator positive and the denominator negative to make it look better when it is displayed
*/
void Fraction::simplify()
{
    if (den == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    int gcd = std::gcd(num, den);
    num /= gcd;
    den /= gcd;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

/*
    This overloads the + operator to correctly calculate using the formula for adding fractions and then correctly displays it after
 */
Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.num*rhs.den + rhs.num*lhs.den, lhs.den*rhs.den);
}

/*
    This overloads the - operator to correctly calculate using the formula for subtracting fractions and then correctly displays it after
 */
Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.num*rhs.den - rhs.num*lhs.den, lhs.den*rhs.den);
}

/*
    This overloads the * operator to correctly calculate using the formula for multiplying fractions and then correctly displays it after
 */
Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.num*rhs.num, lhs.den*rhs.den);
}

/*
    This overloads the / operator to correctly calculate using the formula for dividing fractions and then correctly displays it after
 */
Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.num*rhs.den, rhs.num*lhs.den);
}

/*
    I had to use GPT to learn how to override an ostream
    This override prints the fraction by first printing the numerator, followed by a '/' and then printing the denominator
    In turn, this prints a fraction in the correct format
 */
std::ostream& operator<<(std::ostream& os, const Fraction& lhs)
{
    os << lhs.num << '/' << lhs.den;
    return os;
}
