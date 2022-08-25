#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 標準入力を取得
    long stack[100];
    unsigned short current_index = 0;

    string t;
    while (cin >> t) {
        if (t == "+") {
            stack[current_index - 2] = stack[current_index - 2] + stack[current_index - 1];
            current_index--;
        } else if (t == "-") {
            stack[current_index - 2] = stack[current_index - 2] - stack[current_index - 1];
            current_index--;
        } else if (t == "*"){
            stack[current_index - 2] = stack[current_index - 2] * stack[current_index - 1];
            current_index--;
        } else {
            stack[current_index] = stoi(t);
            current_index++;
        }
    }

    cout << stack[0] << endl;


    return 0;
}

