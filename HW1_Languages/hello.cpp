#include <iostream>
#include <string>
// namespace scoping to support large distributed code
using namespace std;

void hello(string name);

int main(int argc, char* argv[]) {
    out << "Hello C++!" << endl; 
    // argc is number of command line tokens 
    for (int i = 0; i < argc; ++i) 
        // string is a constructor and returns a string object 
        hello(string(argv[i])); 
    return 0; 
} 
 
void hello(string name) { 
    cout << "Hello " << name << endl; 
} 
