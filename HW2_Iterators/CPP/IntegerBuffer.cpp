// IntegerBuffer.cpp
#include "IntegerBuffer.h"

bool IntegerBuffer::add(int value) {
    if (dataLength < dataCapacity) {
        data[dataLength] = value;
        ++dataLength;
        return true;
    } else
        return false;
}

int IntegerBuffer::add(int values[], int numValues) {
    int count = 0;
    for (int i = 0; i < numValues; ++i)
        if (add(values[i]))
            ++count;
    return count;
}
