#ifndef ASSERT_H
#define ASSERT_H
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Assert {
public:
    static void isTrue(bool actual) {
        if (actual)
            cout << "OK" << endl;
        else
            cout << "FAIL" << endl;
    }

    static void isFalse(bool actual) {
        isTrue(!actual);
    }

    static void equals(int expected, int actual) {
        isTrue (expected == actual);
    }

    static void equals(string expected, string actual) {
        isTrue (expected.compare(actual) == 0);
    }

    template <typename T>
    static void equals(const T& expected, const T& actual) {
        isTrue(expected == actual);
    }
};

#endif

