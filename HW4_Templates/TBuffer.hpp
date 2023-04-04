
//
// Created by Taylor Hancock on 03/07/23.
//

#ifndef HW4_TEMPLATES_TBUFFER_HPP
#define HW4_TEMPLATES_TBUFFER_HPP

#include <iostream>
#include <iomanip>

template<typename T, int N>
class TBuffer {
protected:
    T data[N];
    int capacity;
    int dataLength;
    T zeroValue;
public:
    TBuffer(T zeroValue) : capacity(N), dataLength(0), zeroValue(zeroValue) {};
    virtual int add(T value);
    int add(const T array[], int length);
    T sum();
    void print(int col_width, int row_width) const;
};

template<class T, int N>
int TBuffer<T, N>::add(T value) {
    if (dataLength < capacity) {
        data[dataLength] = value;
        ++dataLength;
        return 1;
    }
    else
        return 0;
}

template<class T, int N>
int TBuffer<T, N>::add(const T array[], int length) {
    int count = 0;
    for (int i = 0; i < length; ++i)
        count += add(array[i]);
    return count;
}

template<class T, int N>
T TBuffer<T, N>::sum() {
    T sum = zeroValue;
    for(int i = 0; i < dataLength; i++) {
        sum += data[i];
    }
    return sum;
}

template<class T, int N>
void TBuffer<T, N>::print(int col_width, int row_width) const {
    for (int i = 0; i < dataLength; ++i) {
        // check if value should start a new row
        if (i % row_width == 0 && i > 0)
            std::cout << '\n';
        std::cout << std::setw(col_width) << data[i];
    }
    std::cout << std::endl;
}

#endif //HW4_TEMPLATES_TBUFFER_HPP
