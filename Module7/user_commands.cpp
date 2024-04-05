// Handling user commands

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
struct Course {
    string code, name, lecturer;
};

struct Courselist {
    Course courses[MAX];
    int count = 0;
    int add(string code, string name, string lecturer) {
        if (count < MAX) {
            courses[count].code = code;
            courses[count].name = name;
            courses[count].lecturer = lecturer;
            count++;
        }
        return 0;
    }
    void show(string code) {
        for (int i = 0; i < count; i++) {
            if (courses[i].code == code) {
                cout << "Name: " << courses[i].name << ", Lecturer: " << courses[i].lecturer << endl;
                return;
            }
        }
    }
};

int main() {
    string input;
    cin >> input;
    Courselist course_list;
    while (input != "exit") {
        if (input == "add") {
            // handle add commnad
            string data[3];
            cin >> data[0] >> data[1] >> data[2];
            course_list.add(data[0], data[1], data[2]);
        }
        if (input == "show") {
            // handle show commnad
            string data[1];
            cin >> data[0];
            course_list.show(data[0]);
        }
        cin >> input;
    }
    return 0;
}
