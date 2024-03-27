#include <iostream>
#include <string>
#include <cmath>
using namespace std;

char encryption(int key1, int key2, char letter);
char decryption(int key1, int key2, char letter);
bool check_within_a_z(char test);
void convert_position_alphabet(char &letter);
int find_mmi(int a, int mod_value);
// gcd() is redundant, since given the assumption:
// "Input key a will always be a valid key such that decryption is possible."
// invalid key will gcd(a, 26) > 1, hence not having
// modular multiplicative inverse, hence not able to decrypt
// details are mentioned in the decryption() function below.
int gcd(int a, int b);


int main(){
    char mode;
    int key1, key2;
    string input;
    cin >> mode >> key1 >> key2;
    char character;
    while(true){
        cin >> character;
        input.push_back(character);
        if (character == '!'){
            break;
        }
        else{
            input.push_back(' ');
        }
    }
    switch(mode){
        case 'e':
            for (int i=0; i < input.length(); i++){
                if (check_within_a_z(input[i])){
                    cout << encryption(key1, key2, input[i]);
                }
                else{
                    cout << input[i];
                }
            }
            cout << endl;
            break;
        case 'd':
            for (int i=0; i < input.length(); i++){
                if (check_within_a_z(input[i])){
                    cout << decryption(key1, key2, input[i]);
                }
                else{
                    cout << input[i];
                }
            }
            cout << endl;
            break;
    }
    return 0;
}

char encryption(int key1, int key2, char letter){
    bool upper_case = isupper(letter);
    convert_position_alphabet(letter);
    // y = (ax+b) mod 26
    letter = abs((letter*key1+key2) % 26);
    if (upper_case){
        // change to lowercase
        letter = letter + 97;
    }
    else{
        // original was lowercase, change to upper
        letter = letter + 65;
    }
    return letter;
}

char decryption(int key1, int key2, char letter){
    bool upper_case = isupper(letter);
    // Assumption:
    // Input key a will always be a valid key such that decryption is possible.
    // Meaning that if gcd(key1, 26) != 1, then we are fked :()
    // for example, "e 4 25 w !" gives "J !",
    // but "d 4 25 J !" gives "j !"
    // since 4 and 26 are not coprime, there is no modular multiplicative inverse
    // for 4, so we cannot decrypt the message.
    // TLDR: The code should NEVER reach the else part
    // If it reaches, it means the key1 and 26 are not coprime
    // Indicating INVALID KEY
    if (gcd(key1, 26) == 1){

        convert_position_alphabet(letter);
        int mmi_of_a = find_mmi(key1,26);
        int y = mmi_of_a*(letter-key2) % 26;
        if (y < 0){
            y += 26;
        }
        letter = y;
        if (upper_case){
            letter = letter + 97;
        }
        else{
            letter = letter + 65;
        }
        return letter;
    }
    else{
        // NOTE: If we ever reached here, then it means that the key is invalid
        // The program should not reach here in the first place
        // If you want to try out the brute force method, you can 
        // Change the condition if (gcd(key1, 26) == 1) to if (false)
        // brute force method
        return '!'; // comment this line if you want to try out the brute force method
        int change_case = upper_case ? 32 : 0;
        for (int i = 65+change_case; i < 91+change_case; i++){
            if (encryption(key1, key2, (char)i) == letter){
                return i;
            }
        }
    }
    return letter;
}

int find_mmi(int a, int mod_value){
    // find the modular multiplicative inverse a^-1 by brute force
    // such that a*a^-1 = 1 (mod mod_value)
    // todo: proof this is correct
    for (int i = 1; i <= mod_value; i++){
        if (abs(a*i % mod_value) == 1){
            return i;
        }
    }
    return -1; // indicate no mmi exists
    // which indicate a and mod_value are not coprime
    // in this program, it means that the key is invalid
    // Note: This function should never return -1 as you should check their gcd() first
    // before using find_mmi();
}

void convert_position_alphabet(char &letter){
    if ((int)letter >= 97){
        // convert to upper case
        letter = ((int)letter - 32);
    }
    letter = (int)letter - 65;
}

bool check_within_a_z(char test){
    if (((int)test >= 65) && ((int)test <= 90) || ((int)test >= 97) && ((int)test <= 122)){
        return true;
    }
    else{
        return false;
    }
}

int gcd(int a, int b){
    while(a != b){
        if (a>b){
            a -= b;
        }
        else if (a<b){
            b -= a;
        }
        else{
            break;
        }
    }
    return a;
}
