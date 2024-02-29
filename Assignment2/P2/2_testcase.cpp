#include <iostream>
#include <cassert>
#include "bounding.h"
using namespace std;

void check_and_reset(int& x1, int& y1, int& w1, int& h1, int x2, int y2, int w2, int h2){
    assert(x1 == x2 && y1 == y2 && w1 == w2 && h1 == h2);
    x1 = 0;
    y1 = 0;
    w1 = 10;
    h1 = 10;
}

int main(){
    int x1 = 0;
    int y1 = 0;
    int w1 = 10;
    int h1 = 10;
    cout << "question2-----ext1" << endl;
    assert(mergeBoundingBoxes(x1,y1,w1,h1,5,5,10,10) == true);
    check_and_reset(x1,y1,w1,h1,0,0,15,15);
    cout << "question2-----ext2" << endl;
    assert(mergeBoundingBoxes(x1,y1,w1,h1,5,-5,10,10) == true);
    check_and_reset(x1,y1,w1,h1,0,-5,15,15);
    cout << "question2-----ext3" << endl;
    assert(mergeBoundingBoxes(x1,y1,w1,h1,-5,-5,10,10) == true);
    check_and_reset(x1,y1,w1,h1,-5,-5,15,15);
    cout << "question2-----ext4" << endl;
    assert(mergeBoundingBoxes(x1,y1,w1,h1,-5,5,10,10) == true);
    check_and_reset(x1,y1,w1,h1,-5,0,15,15);
    return 0;
}
