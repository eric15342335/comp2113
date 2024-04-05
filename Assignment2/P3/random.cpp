#include "random.h"
#include <cstdlib>
using namespace std;

void randomPoint(double & x, double & y) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
}