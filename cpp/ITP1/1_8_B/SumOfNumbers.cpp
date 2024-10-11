#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // get line.
    string s;
    while (cin >> s) {
        // if "s == 0" end of data.
        if (s == "0") {
            break;
        }

        // get char and convert char to int.
        int stringSize = s.size();
        int sum = 0;
        for (int i = 0; i < stringSize; i++) {
            sum += s.at(i) - '0';
        }

        // print result.
        cout << sum << endl;
    }

    return 0;
}

