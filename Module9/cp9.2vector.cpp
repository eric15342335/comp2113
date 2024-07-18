#include <vector>
#include <iostream>
#include <string>
using namespace std;

void print(vector<string> v) {
    // vector has two methods to print itself:
    // either use an iterator or use the [] operator
    vector<string>::iterator vitr;
    cout << "Items: ";
    for (vitr = v.begin(); vitr != v.end(); vitr++) {
        cout << *vitr;
        if (vitr != v.end() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    vector<string> items;
    print(items);
    items.push_back("eggs");
    items.push_back("milk");
    items.push_back("sugar");
    items.push_back("chocolate");
    items.push_back("flour");
    print(items);
    items.pop_back();
    print(items);
    items.push_back("coffee");
    print(items);
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i] == "sugar") {
            items[i] = "honey";
        }
    }
    print(items);
    vector<string>::iterator it;
    // vector<string> items;
    for (it = items.begin(); it != items.end(); it++) {
        if (*it == "milk") {
            items.erase(it);
            break;
        }
    }
    print(items);
    return 0;
}
