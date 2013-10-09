#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int h, w;
    while(cin >> h >> w) {

        // if "0 0" then end of data.
        if (h == 0 && w == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            // print dots.
            for (int j = 0; j < w; j++) {
                if ((i + j) % 2 == 0) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }

        // print blank line.
        cout << endl;
    }

    return 0;
}

