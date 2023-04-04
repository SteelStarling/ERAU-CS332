#include <iostream> 
#include <string> 
// name scoping to support large distributed code 
using namespace std; 
 
// As in C, function types must be known before use 
template <typename T> void hello(T name); 
 
int main(int argc, char* argv[]) { 
    cout << "Hello C++!" << endl; 
    // argc is the number of command line tokens (not just args) 
    for (int i = 1; i < argc; ++i) 
        // function on string will be generated from the template 
        hello(string(argv[i])); 
    // function on integer will be generated from the template 
    hello(99); 
    return 0; 
} 
 
// C++ supports compile-time type inferencing for function templates 
template <typename T> 
void hello(T name) { 
    cout << "Hello " << name << endl; 
}
