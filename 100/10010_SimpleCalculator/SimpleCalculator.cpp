#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int a, b;
    char c;

    while (true) {
        cin >> a >> c >> b;

        if (c == '?') { break; }

        int answer;
        switch (c) {
            case '+' :
                answer = a + b;
                break;
            case '-' :
                answer = a - b;
                break;
            case '*' :
                answer = a * b;
                break;
            case '/' :
                answer = a / b;
        }
        cout << answer << endl;
    }
    
    return 0;
}
