#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const* argv[])
{
    int pointNum;
    int counter = 0;
    while (cin >> pointNum) {

        if (pointNum == 0) {
            // if 0 end of problem.
            break;
        }

        counter++;

        double area = 0;
        double points[2][pointNum];
        
        // read first point
        cin >> points[0][0] >> points[1][0];

        // read and calc area
        for (int i = 1; i < pointNum; i++) {
            // read point
            cin >> points[0][i] >> points[1][i];
            
            double tmpX = points[0][i-1] - points[0][i];
            double tmpY = points[1][i-1] + points[1][i];

            area += tmpX * tmpY;
        }

        // last point
        double tmpX = points[0][pointNum - 1] - points[0][0];
        double tmpY = points[1][pointNum - 1] + points[1][0];
        area += tmpX * tmpY;

        // fix area.
        area /= -2.0;

        printf("%d %.1f\n", counter, area);
    }

    return 0;
}
