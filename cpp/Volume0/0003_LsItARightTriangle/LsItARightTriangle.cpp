#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // Get number of three side form.
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        // Get three side form.
        int side[3];
        cin >> side[0] >> side[1] >> side[2];

        // Sort a <= b <= c
        sort(side, side + 3, less<int>());

        // Check right triangle.
        // if (c^2 = a^2 + b^2) and (a <= b <= c),
        // then right triangle.
        int ab = pow(side[0], 2) + pow(side[1], 2);
        int c = pow(side[2], 2);
        if (c == ab) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
