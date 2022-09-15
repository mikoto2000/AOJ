#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 出力する高番号 n を取得
    unsigned short n;
    cin >> n;

    if (n == 0 || n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int pre1 = 1;
    int pre2 = 1;

    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
            pre1 = pre1 + pre2;
        } else {
            pre2 = pre1 + pre2;
        }
    }

    // 結果出力
    cout << pre1 + pre2 << endl;

    return 0;
}

