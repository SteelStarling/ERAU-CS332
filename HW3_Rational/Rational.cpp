//
// Created by thanc on 02/23/2023.
//

#include "Rational.h"

Rational Rational::operator*(const Rational& rhs) const {
    Rational ans(rhs.getNumerator() * this->getNumerator(),
                 rhs.getDenominator() * this->getDenominator());

    return ans;
}

Rational Rational::operator/(const Rational& rhs) const {
    Rational ans(rhs.getDenominator() * this->getNumerator(),
                 rhs.getNumerator() * this->getDenominator());

    return ans;
}
Rational Rational::operator+(const Rational& rhs) const {
    Rational ans((rhs.getNumerator() * this->getDenominator()) + (rhs.getDenominator() * this->getNumerator()),
                 rhs.getDenominator() * this->getDenominator());

    return ans;
}
Rational Rational::operator-(const Rational& rhs) const {
    Rational ans( (rhs.getDenominator() * this->getNumerator()) - (rhs.getNumerator() * this->getDenominator()),
                  rhs.getDenominator() * this->getDenominator());

    return ans;
}

Rational& Rational::operator=(const Rational& rhs) {
    this->setNumerator(rhs.getNumerator());
    this->setDenominator(rhs.getDenominator());
    return *this;
}

Rational::operator double() const {
    return double(getNumerator()) / double(getDenominator());
}

bool Rational::operator==(const Rational& rhs) const {
    return rhs.getNumerator() == this->getNumerator() && rhs.getDenominator() == this->getDenominator();
}

bool Rational::operator!=(const Rational& rhs) const {
    return rhs.getNumerator() != this->getNumerator() || rhs.getDenominator() != this->getDenominator();
}


std::ostream& operator<<(std::ostream& os, const Rational& rhs) {
    os << "(" << rhs.getNumerator() << "/" << rhs.getDenominator() << ")";
    return os;
}

// Code style borrowed from slides from CS225 (I figure I may not be the only one to do this)
std::istream& operator>>(std::istream& is, Rational& rhs) {
    int num = 0, denom = 1;
    int valuesFound = scanf("(%d/%d)", num, denom);
    if(valuesFound == 2) { // ONLY USE IF 2 VALUES ARE FOUND!
        rhs.setNumerator(num);
        rhs.setDenominator(denom);
    }
    return is;
}

/* ------------ Functions provided by Dr. Van Hilst ------------ */

// helper function just for use in this file
// Euclid's algorithm for gcd leverages the fact than any common
// factor of a and b must also be a factor of a - b. So we narrow in
// on that factor by successively replacing the larger of a or b
// with |a - b|.
static int getGCD(int a, int b) {
    // operands must be positive
    if (a < 0)
        a = -a;
    // in case you are wondering, writing a = (a < 0) ? -a : a;
    // uses 1 less line of code, but is more than 2x slower.
    // using a = abs(a); has similar performance to (a < ) ? -a : a
    if (b < 0)
        b = -b;
    while (a != b) {
        if (a > b)
            a -= b; // a = a - b;
        else
            b -= a; // b = b - a;
    }
    return a;
}

// simplify to lowest terms with positive denominator
void Rational::normalize() {
    // zero is a special case
    if (numerator == 0) {
        denominator = 1;
    } else {
        // divide out the greatest common divisor
        int gcd = getGCD(numerator, denominator);
        if (gcd > 1) {
            numerator /= gcd;
            denominator /= gcd;
        }
        // make the denominator positive
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
}
