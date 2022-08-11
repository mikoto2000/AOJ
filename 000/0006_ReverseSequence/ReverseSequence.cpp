#include <algorithm>
#include <iostream>

using namespace std;

string reverse(string str, int start, int end);

int main(int argc, char* argv[]) {

    // 文字列を取得
    string str;
    cin >> str;

    // 文字列を反転
    std::reverse(str.begin(), str.end());

    // 結果を出力
    cout << str << endl;

    return 0;
}

