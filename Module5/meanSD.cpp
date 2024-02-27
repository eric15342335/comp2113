#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double mean_5(double a, double b, double c, double d, double e){
    return (a+b+c+d+e)/5;
}

double sd_5(double mean, double a, double b, double c, double d, double e){
    return sqrt((pow(a-mean, 2)+pow(b-mean, 2)+pow(c-mean, 2)+pow(d-mean, 2)+pow(e-mean, 2))/5);
}


int main(){
    double a,b,c,d,e,mean,sd = 0;
    cin >> a >> b >> c >> d >> e;
    mean = mean_5(a,b,c,d,e);
    // set the number of decimal points to be printed
    // uses #include <iomanip>
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    // now it will print 1.23 instead of 1.23456789
    cout << "Mean = " << mean << endl;
    cout << "Standard deviation = " << sd_5(mean,a,b,c,d,e) << endl;
    return 0;
}
