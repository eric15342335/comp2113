#include <string>
#include <iostream>
using namespace std;

int main() {
    string input;                   // store the user input string
    getline(cin, input);            // get the whole line as requested
    cout << input.length() << endl; // print the length of the string
    // get the substring after the last space
    string input_substr = input.substr(input.rfind(' ') + 1, input.length() - input.rfind(' ') - 1);
    cout << input_substr << endl;
    // vowel counting
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    for (long long unsigned int index = 0; index < input_substr.length(); index++) {
        switch (tolower(input_substr[index])) {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        }
    }
    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "o: " << o << endl;
    cout << "u: " << u << endl;
    return 0;
}
