#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // ifstream is input file stream, ofstream is output file stream
    ifstream file; // or ifstream file ("temperature.txt"); syntax also works
    file.open("temperature.txt");
    if (file.fail()) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    ofstream average_file;
    average_file.open("average.txt");
    if (average_file.fail()) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    string one_line;
    average_file << fixed << setprecision(1);
    // for each line
    while (getline(file, one_line)) {
        string date;
        int count = 0;
        double sum = 0;
        istringstream line_stream(one_line);
        line_stream >> date;
        double temperature;
        // for each temperature in the line (total 24 temps)
        while (line_stream >> temperature) {
            sum += temperature;
            count++;
        }
        double average = sum / count;
        average_file << date << " " << average << endl;
    }
    file.close();
    average_file.close();
    return 0;
}