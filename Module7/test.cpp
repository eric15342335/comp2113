#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int random_num(void){
    return rand() % 100;
}

int main(){
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        cout << "Random number: " << random_num() << endl;
    }
    return 0;
}