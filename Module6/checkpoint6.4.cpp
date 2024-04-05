#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int i;
	cin >> i;
	int a[15];
	for (int j = 0; j < ((i > 15) ? 15 : i); j++) {
		a[j] = j * j;
	}
	for (int j = i; j < ((15 > i + 5) ? i + 5 : 15); j++) {
		a[j] = 0;
	}
	for (int j = i + 5; j < 15; j++) {
		a[j] = pow(3, j);
	}
	for (int j = 0; j < 15; j++) {
		cout << a[j] << " ";
	}
}
