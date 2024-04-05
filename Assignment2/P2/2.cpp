#include "bounding.h"
#include <iostream>
using namespace std;

// eric15342335
// remember to copy this back to the previous directory
// hand in with 1.cpp and Makefile

bool mergeBoundingBoxes(int & x1, int & y1, int & w1, int & h1, int x2, int y2,
                        int w2, int h2) {
    // the bottom right corner of the first box
    int x1_ = x1 + w1;
    int y1_ = y1 + h1;
    // the bottom right corner of the second box
    int x2_ = x2 + w2;
    int y2_ = y2 + h2;
    bool overlap = false;
    // previous assumption: x1,y1 is closer to the top left corner
    // x2,y2 is closer to the bottom right corner
    // however, this assumption is not always true as the question didn't state
    // that test cases may provide different inputs, hence we need to check
    // which corner is closer to the top left corner (0,0)
    // x2 > x1 : check if the second box is more to the right
    if ((x1_ > x2) && (y1_ > y2) && (x1 < x2) && (y1 < y2)) {
        overlap = true;
    }
    // if the second box is more to the top left corner,
    // compare the bottom right corner of the first box with the top left corner
    // of the second box
    else if ((x2_ > x1) && (y2_ > y1) && (x1 > x2) && (y1 > y2)) {
        overlap = true;
    }
    else if ((x1_ > x2) && (y2_ > y1) && (x1 < x2) && (y1 > y2)) {
        overlap = true;
    }
    else if ((x2_ > x1) && (y1_ > y2) && (x1 > x2) && (y1 < y2)) {
        overlap = true;
    }
    // the width and height of the merged box
    // note: the use of max() and min() here is important
    // because the top left corner of the merged box is
    // *NOT* necessarily be the top left corner of the first box
    w1 = max(x1_, x2_) - min(x1, x2);
    h1 = max(y1_, y2_) - min(y1, y2);
    x1 = min(x1, x2);
    y1 = min(y1, y2);
    return overlap;
}
