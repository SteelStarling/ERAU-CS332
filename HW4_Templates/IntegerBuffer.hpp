
//
// Created by Taylor Hancock on 03/07/23.
//

#ifndef HW4_TEMPLATES_INTEGERBUFFER_HPP
#define HW4_TEMPLATES_INTEGERBUFFER_HPP

#include <iostream>
#include <iomanip>

class TBuffer {
protected:
    int data[32];
    int capacity;
    int dataLength;
    int zero_value;
public:
    TBuffer() : capacity(32), dataLength(0), zero_value(0) {};
    int add(int value);
    int add(const int array[], int length);
    void print(int col_width, int row_width) const;
};

int IntegerBuffer::add(int value) {
    if (dataLength < capacity) {
        data[dataLength] = value;
        ++dataLength;
        return 1;
    }
    else
        return 0;
}

int IntegerBuffer::add(const int array[], int length) {
    int count = 0;
    for (int i = 0; i < length; ++i)
        count += add(array[i]);
    return count;
}

void IntegerBuffer::print(int col_width, int row_width) const {
    for (int i = 0; i < dataLength; ++i) {
        // check if value should start a new row
        if (i % row_width == 0 && i > 0)
            std::cout << '\n';
        std::cout << std::setw(col_width) << data[i];
    }
    std::cout << std::endl;
}

#endif //HW4_TEMPLATES_INTEGERBUFFER_HPP
