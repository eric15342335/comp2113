#include <iostream>
using namespace std;

// ### Implement birthday() here ###
void birthday(int& b){
    // pass by reference
    // int& b vs int &b <-- no difference
    b++;
}

// ###

int main(){
    int myAge;
    cin >> myAge;
    birthday(myAge);
    cout << "My age after birthday is " << myAge;
}
