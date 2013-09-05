#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const* argv[])
{
    int a,b;

    cin >> a >> b;

    int d,r;
    double f;

    d = a / b;
    r = a % b;
    f = (double)a / (double)b;

    printf("%d %d %.5lf\n", d, r, f);
    
    return 0;
}
