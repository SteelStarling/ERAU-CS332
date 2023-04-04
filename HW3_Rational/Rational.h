//
// Created by thanc on 02/23/2023.
//

#include <iostream>

#ifndef HW3_RATIONAL_RATIONAL_H
#define HW3_RATIONAL_RATIONAL_H


class Rational {
private:
    int numerator;
    int denominator;
    void normalize();
public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if(denominator == 0) { // prevent invalid denominators
            numerator = 0;
            denominator = 1;
        }

        this->normalize();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    int setNumerator(int num) { numerator = num; }
    int setDenominator(int denom) { denominator = denom; }

    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;
    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational& operator=(const Rational& rhs);
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;

    operator double() const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
    friend std::istream& operator>>(std::istream& is, Rational& rhs);
};


#endif //HW3_RATIONAL_RATIONAL_H
