#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int count = 1;
    int x;

    while (true) {
        cin >> x;
        if (x == 0) { break; }
        cout << "Case " << count++ << ": " << x << endl;
    }
    
    return 0;
}
