/* Please write a program that reads user input repeatedly until -1 is entered,
and display the average of the inputted values.
# Input specification
A sequence of double values until user input -1.
You can assume that users will always input double values.
# Output specification
If the user enters -1, the program will print out the average of the values input
(excluding the -1 in the calculation of average value) and the program ends
(without ending newline at the end). You can assume that users will input at least one value
so there will always be an average value computed by your program.
# Example
Suppose user input the following:
2.5 2.5 3.5 1.5 -1
The program output the following:
2.5
*/

#include <iostream>
using namespace std;

int main() {
    double values, inputs;
    int count = 0;
    while (true) {
        cin >> inputs;
        if (inputs == -1) {
            break;
        }
        else {
            values += inputs;
            count += 1;
        }
    }
    if (count) {
        cout << values / count;
    }
    return 0;
}
