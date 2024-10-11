#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool is_subsequence(string str, string sub) {
    if (sub.size() > str.size()) return false;

    size_t start_index = 0;
    for (int i = 0; i < sub.size(); i++) {
        auto find_index = str.find(sub[i], start_index);

        if (find_index == string::npos) {
            return false;
        }

        start_index = find_index + 1;
    }

    return true;
}

int dfs(string x, string y, string sub, int current_index) {

    //cout << "x : " << x << endl;
    //cout << "y : " << y << endl;
    //cout << "sub : " << sub << endl;
    //cout << "current_index : " << current_index << endl;

    // y のサイズを超えたらもう見つからないという事
    if (current_index > y.size()) return 0;

    // current_index の文字を使う
    int result1 = dfs(x, y, sub + y.substr(current_index, 1), current_index + 1);
    //cout << "result1 : " << result1 << endl;

    // current_index の文字を使わない
    int result2 = dfs(x, y, sub, current_index + 1);
    //cout << "result2 : " << result2 << endl;

    int result3 = 0;
    if (is_subsequence(x, sub)) {
        result3 = sub.size();
    }
    //cout << "result3 : " << result3 << endl;

    return max({result1, result2, result3});
}

int main(int argc, char* argv[]) {

    // データセットの数 q を取得
    unsigned short q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        // 文字列 X, Y を取得
        string x, y;
        cin >> x >> y;

        string l, s;

        if (x.size() > y.size()) {
            l = x;
            s = y;
        } else {
            l = y;
            s = x;
        }

        // 空文字は部分文字列として認識されてしまうので、一文字目から開始
        cout << dfs(l, s, "", 0) << endl;

    }

    return 0;
}

