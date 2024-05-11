#include <iostream>
#include <string>
#include <list>
using namespace std;

class student {
  public:
    string name;
    string major;
    int number;
};

int main() {
    string input;
    list<student> record;
    while (true) {
        cin >> input;
        student temp;
        if (input == "Add") {
            cin >> temp.name >> temp.major >> temp.number;
            record.push_back(temp);
            cout << "Added Successfully" << endl;
        }
        else if (input == "Search") {
            list<student>::iterator itr;
            bool found = false;
            cin >> temp.name >> temp.major;
            for (itr = record.begin(); itr != record.end(); itr++) {
                if (itr->name == temp.name && itr->major == temp.major) {
                    cout << "Student number:" << itr->number << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No Record found" << endl;
            }
        }
        else if (input == "Quit") {
            cout << "Bye" << endl;
            break;
        }
    }
}
