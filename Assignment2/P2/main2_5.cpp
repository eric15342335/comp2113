#include <iostream>
#include "bounding.h"
using namespace std;

int main() {

  int x1 = 15;
  int y1 = 15;
  int w1 = 1;
  int h1 = 1;

  int x2 = 10;
  int y2 = 5;
  int w2 = 1;
  int h2 = 1;

  int x3 = 5;
  int y3 = 10;
  int w3 = 1;
  int h3 = 1;

  mergeBoundingBoxes(x1, y1, w1, h1, x2, y2, w2, h2);
  mergeBoundingBoxes(x1, y1, w1, h1, x3, y3, w3, h3);

  cout << x1 << " " << y1 << " " << w1 << " " << h1 << endl;

}