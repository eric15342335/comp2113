#include <iostream>
using namespace std;

int main() {
    unsigned long long int p, a, b, c;
    cin >> p;
    for (a = 1; a < p / 2; a++) {
        // given a*a+b*b=c*c a+b+c=p
        // we can express b in terms of p and a
        // since we have 4 unknown variables and 2 equations
        b = p * (p - 2 * a) / (2 * (p - a));
        c = p - a - b;
        // check to ensure
        if ((a * a + b * b == c * c) && (a < b) && (b < c)) {
            cout << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}
