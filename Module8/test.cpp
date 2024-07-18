#include <iostream>
using namespace std;

int main() {
    string b = "helo";
    const char * a = b.c_str();
    // c_str() returns c-string character array
    // since array is actually a pointer pointing to the start of array
    // the data type is const char *
    cout << a; // no need dereference

    cout << (1 < -2 && 2 < 3);
}
