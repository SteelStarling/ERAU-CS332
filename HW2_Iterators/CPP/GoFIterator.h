// GoFIterator.h
#ifndef GOF_ITERATOR_H
#define GOF_ITERATOR_H

class GoFIterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual int currentItem() = 0;
};
#endif // GOF_ITERATOR_H
