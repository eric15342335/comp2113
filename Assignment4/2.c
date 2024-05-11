#include <stdio.h>
#include <string.h>

int main(void) {
    char inputs[501];
    // not &inputs because it's already a pointer (to array)
    scanf("%s", inputs);
    char outputs[1001] = "\0";
    // Perform run-length encoding and store the results to 'outputs'
    unsigned int currentCharLength = 0;
    char currentChar = inputs[0];
    for (unsigned int i = 0; i <= strlen(inputs); i++) {
        if (inputs[i] == currentChar) {
            currentCharLength++;
        }
        else {
            outputs[strlen(outputs)] = currentChar;
            // Convert unsigned int with multiple digits to char array.
            sprintf(outputs + strlen(outputs), "%u", currentCharLength);
            outputs[strlen(outputs)] = '\0';
            currentChar = inputs[i];
            currentCharLength = 1;
        }
    }
    // Print the results and display compression rate.
    printf("%s\n", outputs);
    // Automatic type convertion to double on the first variable,
    // result in final result as double.
    printf("%.3f", (double)strlen(outputs) / strlen(inputs));
}
