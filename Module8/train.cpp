#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Car {
    string id;
    Car * next;
};

void appendCar(Car *& head, string id);
void printTrain(Car *& head);

int main() {
    Car * head = NULL;
    int n;
    cin >> n;
    string id;
    for (int i = 0; i < n; i++) {
        cin >> id;
        appendCar(head, id);
    }
    printTrain(head);

    return 0;
}

// Please implement the function appendCar() here.
void appendCar(Car *& head, string id) {
    if (head == NULL) {
        head = new Car;
        head->id = id;
        head->next = NULL;
    }
    else {
        Car * current = head;
        // go to the end of the linked list
        while (current->next != NULL) {
            current = current->next;
        }
        Car * append = new Car;
        append->id = id;
        append->next = NULL;
        current->next = append;
    }
}

void printTrain(Car *& head) {
    Car * current = head;
    (*current).next while (current != NULL) {
        if (current->next != NULL) {
            cout << current->id << ", ";
        }
        else {
            cout << current->id;
        }
        current = current->next;
    }
}
