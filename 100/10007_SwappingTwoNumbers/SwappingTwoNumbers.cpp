#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int x,y;
    int min,max;

    while (true) {
        cin >> x >> y;
        if (x == 0 && y == 0) { break; }
        if (x > y) {
            min = y;
            max = x;
        } else {
            min = x;
            max = y;
        }

        cout << min << " " << max << endl;
    }
    
    return 0;
}
