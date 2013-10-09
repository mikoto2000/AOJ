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

        // print top frame.
        for (int i = 0; i < w; i++) {
            cout << "#";
        }
        cout << endl;

        for (int i = 1; i < h - 1; i++) {
            // print left frame.
            cout << "#";

            // print dots.
            for (int j = 1; j < w - 1; j++) {
                cout << ".";
            }

            // print right frame.
            cout << "#";
            cout << endl;
        }
        // print bottom frame.
        for (int i = 0; i < w; i++) {
            cout << "#";
        }
        cout << endl;

        // print blank line.
        cout << endl;
    }

    return 0;
}

