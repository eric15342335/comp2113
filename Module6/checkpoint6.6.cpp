#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, second, third;
    getline(cin, first);
    cin >> second >> third;
    int starting_from = 0;
    while (first.find(second, starting_from) != string::npos) {
        starting_from = first.find(second, starting_from) + third.length();
        first = first.replace(first.find(second, starting_from - third.length()), second.length(), third);
    }
    cout << first;
}
