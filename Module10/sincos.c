#include <stdio.h>
#include <math.h>
#define PI 3.14159265

// Task 2. Build the GetSinCos() function
void GetSinCos(int degree, double *dSin, double *dCos) {
    *dSin = sin(degree * PI / 180);
    *dCos = cos(degree * PI / 180);
}

int main()
{
    double dSin;
    double dCos;
    int degree;
    scanf("%d", &degree);
    GetSinCos(degree, &dSin, &dCos);
    // Task 1. Read in user input to variable degree
    // Task 3. Call the GetSinCos() function
    printf("The sin is %g \n", dSin);
    printf("The cos is %g \n", dCos);

    return 0;
}
