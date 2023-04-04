#include <iostream>
#include <iomanip>
#include "Assert.h"
#include "Rational.h"
using namespace std;

int main() {
    Rational a(1, 3);
    Rational b(100, 1);
    Rational x(0, 0);
    cout << "Handles zero over anything as 0 over 1\n"; 
    Assert::equals(x, a * x);
    Rational y(99, 33);
    cout << "Normalizes Rational(99,33) in the constructor.\n";
    Assert::equals(Rational(3,1), y);
    cout << a << " * " << b << " = " << a * b << endl;
    Assert::equals(Rational(100, 3), a * b);
    a = Rational(3, 7);
    b = Rational(1, 7);
    cout << a << " / " << b << " = " << a / b << endl;
    Assert::equals(Rational(3, 1), a / b);
    a = Rational(1, 3);
    b = Rational(2, 5);
    Assert::isTrue(a != b);
    Assert::isFalse(a == b);
    Rational c = a + b;
    cout << a << " + " << b << " = " << c << endl;
    Assert::equals(Rational(11, 15), c);
    a = Rational(2, 3);
    b = Rational(1, 6);
    cout << a << " - " << b << " = " << a - b << endl;
    Assert::equals(Rational(1, 2), a - b);
    Assert::equals(Rational(0, 1), a - a);
    a = b = c;
    cout << a << " = " << b << " = " << c << endl;
    Assert::equals(Rational(11, 15), a);
    Assert::isTrue(b == c);
    double dValue = a;
    cout << fixed << setprecision(11) << dValue << endl;
    return 0;
}
