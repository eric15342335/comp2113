#include <stdio.h>
#include <string.h>
// Task2. Build the toLower() function here.

void toLower(char a[]){
    // To be implemented by you.
    // strlen is string.length() in C++
    for (int i = 0; i < strlen(a); i++){
        if (a[i] >= 'A' && a[i] <= 'Z'){
            a[i] = a[i] + 32;
        }
    }

}
int main(){
    char input[100];
    // Task 1. Read in user input to the char array input.
    scanf("%s", input);
    toLower(input);
    // Task 3. Call the toLower function.
    printf("%s", input);
}
