#include <iostream>
using namespace std;

// Different order of data members in the struct
// would result in different size of the struct
struct structA {
        char c;
        double d;
        int i;
};

struct structB {
        double d;
        int s;
        char c;
};

int main() {
    cout << sizeof(struct structA) << " " << sizeof(struct structB) << endl;
}