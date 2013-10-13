#include <iostream>
#include <ctype.h>

using namespace std;

int main(int argc, char* argv[]) {

    char c;

    while (cin.get(c)) {
        // check upper or lower case.
        if (islower(c)) {
            c = toupper(c);
        } else if (isupper(c)) {
            c = tolower(c);
        }

        // print result.
        cout << c;

        // if eol, end of data.
        if (c == '\n') {
            break;
        }
    }

    return 0;
}
