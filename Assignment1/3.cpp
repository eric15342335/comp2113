// eric15342335
// problem 3
// Write a C++ program which takes one user input integer n (0 ≤ n ≤ 100000),
// and find all right-angled triangles with
// integer side lengths whose perimeter is n
#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n;
	// given a+b+c=n and a<=b<=c
	// a+b>=c (triangle inequality)
	// a+b+c>=2c (add c)
	// c<=n/2 (obtain an upper bound of c)

	// since a*a+b*b=c*c therefore b*b<c*c b<c
	// assume a=b, then 2a*a=c*c, c=sqrt(2)*a
	// where c is not an integer, contradicts "int c" requirement
	// therefore a<=b can be simplified as a<b

	// assume b=c, then a*a=0 -> a=0 (rej.)
	// .'. b<=c can be simplifies as b<c
	// a+b+c=n -> 3c>n -> c>n/3

	// since c<=n/2 -> n-c>=n/2
	// a+b+c=n -> 2b>n-c -> b>n/4

	// we want output sort in ascending order of a
	// b+c=n-a -> 2b<n-a, when a increase b decrease
	// a+c=n-b -> 2c>=n-b, when b decrease c decrease
	// which means descending order of b and c
	for (c = n / 2; c > n / 3; c--) {
		for (b = c - 1; b > n / 4; b--) {
			a = n - c - b;
			// since the lower bound of b and c are too small, check a<b<c
			if ((a * a + b * b == c * c) && (a < b) && (b < c)) {
				cout << a << " " << b << " " << c << "\n";
			}
		}
	}
	return 0;
}
