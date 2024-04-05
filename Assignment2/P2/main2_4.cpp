#include <iostream>
#include "bounding.h"
using namespace std;

int main() {

    int x1 = 10;
    int y1 = -10;
    int w1 = 10;
    int h1 = 20;

    int x2 = -10;
    int y2 = 10;
    int w2 = 50;
    int h2 = 10;

    bool result = mergeBoundingBoxes(x1, y1, w1, h1, x2, y2, w2, h2);

    if (result) {
        cout << "Overlaps" << endl;
    }
    else {
        cout << "Does not overlap" << endl;
    }
}