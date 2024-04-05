#include "random.h"
#include <iostream>
using namespace std;

int main() {

	int n = 1000000;
	int count = 0;

	for (int i = 0; i < n; ++i) {
		double x, y;
		randomPoint(x, y);
		if (x * x + y * y < 1) {
			++count;
		}
	}

	cout << 4.0 * count / n << endl;

	return 0;
}