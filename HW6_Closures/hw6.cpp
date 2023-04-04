#include <stdlib.h> // for rand()
#include <iostream> // for cout and endl
#include <iomanip>  // for setw()
#include "TBuffer.hpp"
using namespace std;

class TablePrint {
    int column;
public:
    // initialize the column count in the constructor
    TablePrint() : column(0) {}
    // output newline when the table is done (we go out of scope)
    ~TablePrint() {
        cout << endl;
    }
    // overloaded operator() lets an object be used like a function
    void operator()(int x) {
        // count the column to output a newline when needed
        if (++column > 10) {
            cout << endl;
            column = 1;
        }
        cout << setw(5) << x;
    }
};

#define BUFSZ 25

int main() {
    TBuffer<int, BUFSZ> ibuf;
    // fill the buffer with (pseudo) random integers
    for (int i = 0; i < BUFSZ; ++i)
        ibuf.add(rand() % 100);
    // print the numbers in a table using a functor
    ibuf.map(TablePrint());
    // print the numbers all in a row using a lambda

    /* %% TODO: your code goes here %% */

    // sort the numbers low to high using a lambda for the compare

    /* %% TODO: your code goes here %% */

    // compute the sum and average using a closure here

    /* %% TODO: your code goes here %% */

    // print a table like the one above, only this time using a closure

    /* %% TODO: your code goes here %% */

    cout << endl;
    return 0;
}
