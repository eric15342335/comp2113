/*
   This program prompts the user to input a sequence of characters and outputs
   the number of vowels
*/

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char a) {
	string vowels = "A E I O U a e i o u";
	// string.find(char) will return string::npos if not found
	// first character is index 0
	return vowels.find(a) != string::npos;
}

int main() {
	int n;
	int numVowel = 0;
	char c;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> c;
		if (isVowel(c))
			numVowel++;
	}

	cout << "Number of vowels = " << numVowel << endl;

	return 0;
}