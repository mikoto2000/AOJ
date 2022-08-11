#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 文字列 s を取得
    string s;
    getline(cin, s);

    // 文字列 p を取得
    string p;
    getline(cin, p);
    int p_length = p.length();

    // 文字列 s の末尾から文字列 p が始まる場合にマッチさせるため、
    // 文字列 p のサイズ - 1 分、文字列 s の先頭文字を文字列 s 末尾に追加する。
    s.append(s.substr(0, p_length - 1));

    // 文字列 s に文字列 p が含まれるかをテスト
    if (s.find(p) != string::npos) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

