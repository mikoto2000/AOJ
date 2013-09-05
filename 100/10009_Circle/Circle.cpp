#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(int argc, char const* argv[])
{
    double r;

    cin >> r;

    double area = r * r * M_PI;
    double circle = 2.0 * r * M_PI;

    printf("%.5lf %.5lf\n", area, circle);
    
    return 0;
}
