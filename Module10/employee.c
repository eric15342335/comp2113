#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {
        char Name[100];
        char Position[100];
        int Salary;
};

typedef struct Employee Employee;

void setEmployee(char n[], char p[], int sal, Employee * e) {
    // strcpy parameters are (destination, source)
    strcpy(e->Name, n);
    strcpy(e->Position, p);
    e->Salary = sal;
}

void showInfo(Employee e) {
    printf("Name: %s\n", e.Name);
    printf("Position: %s\n", e.Position);
    printf("Salary: %d\n", e.Salary);
}

int main() {
    int numOfEmployee;
    scanf("%d", &numOfEmployee);
    Employee * e;
    e = (Employee *)malloc(numOfEmployee * sizeof(Employee));
    for (int i = 0; i < numOfEmployee; i++) {
        char n[100], p[100];
        int sal;
        scanf("%s%s%d", n, p, &sal);
        setEmployee(n, p, sal, &e[i]);
        // Instead of &e[i], e+i also works since it is an array.
        // What is e+i? It is the address of the i-th element of the array.
        // But why we can directly add i to it? isnt the array address is affected by the size of the struct?
        // Yes, it is. But the compiler knows the size of the struct and it will automatically add the correct amount of bytes to the address.
        // So, e+i is the same as &e[i].
    }
    for (int i = 0; i < numOfEmployee; i++) {
        showInfo(e[i]);
    }
    free(e);
    return 0;
}
