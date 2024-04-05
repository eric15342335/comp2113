/* Write a program that reads an integer and determines and prints whether it is
odd or even. If the integer x is odd, print "x is odd". If x is even, print "x
is even" */

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    // negative values provided in test cases
    if ((x % 2 == 1) || (x % 2 == -1)) {
        cout << x << " is odd";
    }
    else
        cout << x << " is even";
    return 0;
}