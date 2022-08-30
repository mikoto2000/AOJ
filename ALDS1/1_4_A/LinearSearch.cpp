#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 整数の数 n を取得
    unsigned short n;
    cin >> n;

    // 数列 S を取得
    unsigned int s[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // 整数の数 q を取得
    unsigned short q;
    cin >> q;

    // 数列 T を取得
    unsigned int t[n];
    for (unsigned int i = 0; i < q; i++) {
        cin >> t[i];
    }

    // T 内の要素が S に含まれている化を確認してその数を数える
    unsigned short count = 0;

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (t[i] == s[j]) {
                count++;
                break;
            }
        }
    }

    // 結果出力
    cout << count << endl;

    return 0;
}

