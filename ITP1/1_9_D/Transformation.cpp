#include <algorithm>
#include <iostream>

using namespace std;

void print(string str, int start, int end);
string reverse(string str, int start, int end);
string replace(string str, int start, int end, string after);

int main(int argc, char* argv[]) {

    // 文字列を取得
    string str;
    cin >> str;

    // 命令数を取得
    int operation_count;
    cin >> operation_count;

    for (int i = 0; i < operation_count; i++) {
        // 操作取得
        string operation;
        cin >> operation;

        if (operation == "print") {
            // 操作のパラメーターを取得
            int start;
            cin >> start;
            int end;
            cin >> end;

            // 主処理呼び出し
            print(str, start, end);
        } else if (operation == "reverse") {
            // 操作のパラメーターを取得
            int start;
            cin >> start;
            int end;
            cin >> end;

            // 主処理呼び出し
            str = reverse(str, start, end);
        } else if (operation == "replace" ) {
            // 操作のパラメーターを取得
            int start;
            cin >> start;
            int end;
            cin >> end;
            string after;
            cin >> after;

            // 主処理呼び出し
            str = replace(str, start, end, after);
        }
    }

    return 0;
}

void print(string str, int start, int end) {
    // substr における end の位置調整
    end++;

    cout << str.substr(start, end - start) << endl;
}

string reverse(string str, int start, int end) {
    // substr における end の位置調整
    end++;

    string head = str.substr(0, start);
    string target = str.substr(start, end - start);
    std::reverse(target.begin(), target.end());
    string tail = str.substr(end, str.length());

    return head + target + tail;
}

string replace(string str, int start, int end, string after) {
    // substr における end の位置調整
    end++;

    string head = str.substr(0, start);
    string tail = str.substr(end, str.length());

    return head + after + tail;
}

