/*
The formulas for calculating BMI are
BMI = weight(kg) / (height(m) * height(m))
Create a BMI calculator application that reads the user’s weight in kilograms
and then height in meters, then calculates and displays the user’s body mass index.
Also, the application should display the following information so the user
can evaluate his/her BMI:
BMI VALUES
Underweight: less than 18.5
Normal: between 18.5 and 24.9
Overweight: between 25 and 29.9
Obese: 30 or greater

Example
Assume the user is 64 kg in weight and 1.6 m in height, input as follows:
64 1.6
The program outputs the following:
Your BMI = 25
BMI VALUES
Underweight: less than 18.5
Normal: between 18.5 and 24.9
Overweight: between 25 and 29.9
Obese: 30 or greater
*/

#include <iostream>
using namespace std;

int main() {
    int weight;
    double height;
    // take two inputs
    cin >> weight >> height;
    cout << "Your BMI = " << weight / (height * height) << endl;
    cout << "BMI VALUES" << endl;
    cout << "Underweight: less than 18.5" << endl;
    cout << "Normal: between 18.5 and 24.9" << endl;
    cout << "Overweight: between 25 and 29.9" << endl;
    cout << "Obese: 30 or greater";
    return 0;
}
