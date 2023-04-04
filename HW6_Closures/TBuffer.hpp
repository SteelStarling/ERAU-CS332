#ifndef T_BUFFER_H
#define T_BUFFER_H

template <class T, int N> class TBuffer {
    T data[N];
    int dataLength = 0;
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
public:
    // while there is space, add another value to the collection
    bool add(T value) {
        if (dataLength < N) {
            data[dataLength] = value;
            ++dataLength;
            return true;
        } else
            return false;
    }
    // perform operation f for each value in the collection
    template <typename FuncType>
    void map(FuncType funcDo) {
        for (int i = 0; i < dataLength; ++i)
            funcDo(data[i]);
    }
    // bubble-sort the collection using comparison function parameter
    template <typename FuncType>
    void sort(FuncType funcCompare) {
        for (int i = 1; i < dataLength; ++i)
            for (int j = 1; j < dataLength; ++j)
                if (funcCompare(data[j - 1], data[j]) > 0)
                    swap(data[j - 1], data[j]);
    }
};

#endif // T_BUFFER_H
