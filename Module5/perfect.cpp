/*
   This program prints out the perfect numbers between 1 and N
*/

#include <iostream>
using namespace std;

bool isPerfect(int j){
    int sum_factor = 0;
    for (int factor = 1; factor<j; factor++){
        if (j % factor == 0) {
            sum_factor += factor;
        }
    }
    return j == sum_factor;
}

const int N = 1000;

int main()
{
	cout << "For the integers from 1 to " << N << ":\n";

	for (int j = 2; j <= N; ++j)
		if (isPerfect(j))
			cout << j << " is perfect\n";

	cout << endl;

	return 0;
}
