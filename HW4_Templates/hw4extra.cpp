
//
// Created by Taylor Hancock on 03/07/23.
//

#include <string>
#include <iostream>
#include "TBuffer.hpp"
#include "TOrderedBuffer.hpp"
using namespace std;

// fun expecting a reference to a TBuffer<T, N> type object
template<typename T, int N>
void fun(TBuffer<T, N>& thing) {
    thing.print(10, 7);
    cout << "   Sum: " << thing.sum() << endl << endl;
}

// loadBuf template function specialized for int
template<int N>
void loadBuf(TBuffer<int, N>& ib) {
    cout << "int array capacity = " << N << endl;
    int i_array[10] = { 12, -4, 6, 8, 3, 5, 17, -6, 11, 18 };
    ib.add(7);
    ib.add(12);
    ib.add(17);
    ib.add(i_array, 9);
}

// loadBuf template function specialized for string
template<int N>
void loadBuf(TBuffer<string, N>& sb) {
    cout << "string array capacity = " << N << endl;
    string s_array[4] = {"Frege", "Russell", "Goedel", "Turing"};
    sb.add(s_array, 4);
    sb.add("VonNeuman");
    sb.add("Kleene");
    sb.add("Whitehead");
    sb.add("Hoare");
    sb.add("Chomsky");
}

// loadBuf template function specialized for double
template<int N>
void loadBuf(TBuffer<double, N>& db) {
    cout << "double array capacity = " << N << endl;
    db.add(8.463);
    db.add(3.74);
    db.add(5.231);
}

int main() {
    // unsorted ints
    TBuffer<int, 14> ib0(0);
    loadBuf(ib0);
    fun(ib0);

    // sorted ints
    TOrderedBuffer<int, 12> ib1(0);
    loadBuf(ib1);
    fun(ib1);

    // fewer sorted ints
    TOrderedBuffer<int, 8> ib2(0);
    loadBuf(ib2);
    fun(ib2);

    // unsorted strings
    TBuffer<string, 10> sb0("");
    loadBuf(sb0);
    fun(sb0);

    // sorted strings
    TOrderedBuffer<string, 10> sb1("");
    loadBuf(sb1);
    fun(sb1);

    // unsorted doubles
    TBuffer<double, 10> db0(0.0);
    loadBuf(db0);
    fun(db0);

    // sorted doubles
    TOrderedBuffer<double, 10> db1(0.0);
    loadBuf(db1);
    fun(db1);

    return 0;
}