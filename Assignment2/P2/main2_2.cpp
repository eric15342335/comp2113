#include <iostream>
#include "bounding.h"
using namespace std;

int main() {

    int x1 = 1;
    int y1 = 1;
    int w1 = 10;
    int h1 = 10;

    int x2 = 5;
    int y2 = 5;
    int w2 = 10;
    int h2 = 10;

    bool result = mergeBoundingBoxes(x1, y1, w1, h1, x2, y2, w2, h2);

    if (result) {
        cout << "Overlaps" << endl;
    }
    else {
        cout << "Does not overlap" << endl;
    }
}