#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct Car {
	string id;
	Car *next;
};

void appendCar(Car *&head, string id);
void printTrain(Car *&head);

int main() {
	Car *head = NULL;
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
void appendCar(Car *&head, string id) {
    if (head == NULL) {
        head = new Car;
        head->id = id;
        head->next = NULL;
    } else {
        Car *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Car;
        current->next->id = id;
        current->next->next = NULL;
    }
}

void printTrain(Car *&head) {
	Car *current = head; (*current).next
	while (current != NULL) {
		if (current->next != NULL) {
			cout << current->id << ", ";
		}
		else {
			cout << current->id;
		}
		current = current->next;
	}
}

