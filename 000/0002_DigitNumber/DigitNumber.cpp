#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    int i, j;

    while (cin >> i >> j) {
        string s;
        stringstream ss;
        ss << i + j;
        ss >> s;

        cout << s.size() << endl;
    }
}
