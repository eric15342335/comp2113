#include <iostream>
using namespace std;

int main() {
    int input;
    cin >> input;
    int * set = new int[input];
    for (int i = 0; i < input; i++) {
        cin >> set[i];
    }

    int num1 = set[0];
    int count1 = 1;
    for (int i = 0; i < input; i++) {
        int num2 = set[i];
        int count2 = 0;
        for (int i = 0; i < input; i++) {
            if (set[i] == num2) {
                count2++;
            }
        }
        if (count2 > count1) {
            count1 = count2;
            num1 = num2;
        }
    }
    cout << "The mode of the set is " << num1;
    delete[] set;
}
