#include <iostream>
#include <ctype.h>
#include <memory.h>

using namespace std;

int main(int argc, char* argv[]) {

    // initialize count of char.
    int count[26];
    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }

    // count chars.
    char c;
    while (cin >> c) {

        // modify caractor to lower case.
        c = tolower(c);

        // check char and inclement counter.
        int index = c - 'a';
        if (index >= 0
                && index <= 26) {
            count[index]++;
        }
    }

    // print result.
    for (int i = 0; i < 26; i++) {
        char c = i + 'a';
        cout << c << " : " << count[i] << endl;
    }

    return 0;
}

