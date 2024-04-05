#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin, input);
	for (unsigned int i = 0; i < input.length(); i++) {
		if (!isalpha(input[i])) {
			input.erase(i, 1);
			i--; // Decrement i to account for the removed character
		}
	}
	// palindrome check
	bool isPalindrome = true; // Assume the string is a palindrome
	// Compare the first half of the string to the second half
	for (unsigned int i = 0; i < input.length() / 2; i++) {
		// If the characters are not the same, the string is not a palindrome
		if (tolower(input[i]) != tolower(input[input.length() - 1 - i])) {
			isPalindrome = false;
			// Break out of the loop early if the string is not a palindrome
			break;
		}
	}
	cout << "The input string is " << (isPalindrome ? "" : "not ")
		 << "a palindrome." << endl;
	return 0;
}
