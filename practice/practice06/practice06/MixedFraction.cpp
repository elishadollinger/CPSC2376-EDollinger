#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>
#include <limits>
#include <stdexcept>

/*
    This constructor correctly calculates the mixed fraction
    First, the numerator is divided by the denominator to get the whole number of the fraction
    Then, the numerator is modded by the denominator to get the numerator value of the fraction
    Finally, the denominator is kept the same since it does not need to be altered
    For example, if we used 9/4:
    9/4=2, so whole = 2
    9%4=1,, so numer=1
    denom=4
 */
MixedFraction::MixedFraction(const Fraction& frac)
{
    whole = frac.getNum()/frac.getDen();
    numer = frac.getNum() % frac.getDen();
    denom = frac.getDen();
}

/*
    This prints the completed mixed fraction
    First, the whle number of the fraction is printed, which is then followed by a space for formatting
    Then, the numerator is printed, followed by a / and then the denominator to correctly display the fraction in whole number form
    Using our example earlier, it would print as "2 1/4"
 */
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFrac)
{
    os << mixedFrac.whole << ' ' << mixedFrac.numer << '/' << mixedFrac.denom;
    return os;
}
