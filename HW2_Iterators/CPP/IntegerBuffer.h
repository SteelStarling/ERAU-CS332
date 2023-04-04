// IntegerBuffer.h
#ifndef INTEGER_BUFFER_H
#define INTEGER_BUFFER_H
#include "GoFIterator.h"

class IntegerBuffer {
private:
    int data[32];
    int dataLength = 0;
    int dataCapacity = 32;
    class IntegerBufferIterator : public GoFIterator {
    private:
        IntegerBuffer* outer;
        int cursor;
        friend IntegerBuffer;

        IntegerBufferIterator(IntegerBuffer* buf) {
            this->outer = buf;
            cursor = 0;
        }
    public:
        void first() override {
            cursor = 0;
        }
        void next() override {
            if(!isDone()) cursor++;
        }
        bool isDone() override {
            return cursor >= outer->dataLength;
        }
        int currentItem() override {
            return cursor >= 0 && cursor < outer->dataLength ? outer->data[cursor] : 0;
        }
    };
public:
    bool add(int value);
    int add(int* values, int numValues);

    GoFIterator* createIterator() {
        return new IntegerBufferIterator(this);
    }
};
#endif // INTEGER_BUFFER_H
