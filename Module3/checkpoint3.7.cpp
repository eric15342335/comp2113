/* Write a program that inputs a five-digit integer, separates the integer into
its digits and prints them separated by a comma each.
For example, if the user types in
42399
the program should print:
4,2,3,3,9
*/

#include <iostream>
using namespace std;

int main() {
    int x, y = 10000;
    cin >> x;
    for (int i = 5; i > 0; i--) {
        cout << x / y;
        if (i > 1) {
            cout << ",";
        }
        x %= y;
        y /= 10;
    }

    return 0;
}
