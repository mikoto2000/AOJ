#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    // Get input.
    double a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f) {
        // Probrem.
        // ax + by = c ... (1)
        // dx + ey = f ... (2)

        // Modify (1) for x.
        // ax + by = c
        // ax      = c - by
        //  x      = (c - by)/a ... (3)
        
        // Modify (2) for y using (3).
        // d((c - by)/a) +  ey =  f
        // d(c/a - by/a) +  ey =  f
        // dc/a - bdy/a  +  ey =  f
        //      - bdy/a  +  ey =  f - dc/a
        //          ey - bdy/a =  f - dc/a
        //         aey - bdy   = af - dc
        //          (ae - bd)y = af - dc
        //                   y = (af - dc)/(ae - bd) ... (4)

        // Calculate y using (4).
        double y = (a * f - d * c) / (a * e - b * d);

        // Calculate x using (3) and (4).
        double x = (c - b * y)/a;

        printf("%.3f %.3f\n", x, y);
    }       
}
