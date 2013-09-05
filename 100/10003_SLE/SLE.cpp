#include <iostream>

using namespace std;

const char* LESS_THAN = "a < b";
const char* MORE_THAN = "a > b";
const char* EQUALS = "a == b";

int main(int argc, char const* argv[])
{

    int a, b;

    cin >> a >> b;

    const char* output;
    if (a < b) {
        output = LESS_THAN;
    } else if (a > b) {
        output = MORE_THAN;
    } else {
        output = EQUALS;
    }

    cout << output << endl;
    
    return 0;
}
