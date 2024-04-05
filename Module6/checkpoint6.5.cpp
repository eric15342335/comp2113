#include <iostream>
using namespace std;

int main() {
	int length;
	cin >> length;
	double a[15];
	for (int i = 0; i < length; i++) {
		cin >> a[i];
	}
	double mean, variance = 0;
	for (int i = 0; i < length; i++) {
		mean += a[i];
	}
	mean /= length;
	for (int i = 0; i < length; i++) {
		variance += (a[i] - mean) * (a[i] - mean);
	}
	variance /= length;
	cout << "Variance = " << variance;
}