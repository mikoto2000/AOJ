#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 標準入力を取得
    int a, b, c;
    cin >> a >> b >> c;

    // 結果判定
    string result_str;
    if (a < b && b < c) {
        result_str = "Yes";
    } else {
        result_str = "No";
    }

    // 結果出力
    cout << result_str << endl;

    return 0;
}

