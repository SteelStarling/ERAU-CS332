
//
// Created by Taylor Hancock on 03/07/23.
//

#ifndef HW4_TEMPLATES_TORDEREDBUFFER_HPP
#define HW4_TEMPLATES_TORDEREDBUFFER_HPP

#include "TBuffer.hpp"

template<typename T, int N>
class TOrderedBuffer : public TBuffer<T, N> {
public:
    TOrderedBuffer(T zeroValue) : TBuffer<T, N>(zeroValue) {}
    int add(T value) override;
};

template<typename T, int N>
int TOrderedBuffer<T, N>::add(T value) {

    if (this->dataLength < this->capacity) {
        int i = 0;
        // shift things up while looking for place to insert
        for (i = this->dataLength; i > 0 && this->data[i - 1] > value; --i)
            this->data[i] = this->data[i - 1];
        this->data[i] = value;
        ++this->dataLength;
        return 1;
    } else
        return 0;
}


#endif //HW4_TEMPLATES_TORDEREDBUFFER_HPP
