#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 数列の長さを取得
    unsigned short n;
    cin >> n;

    // 数列を取得
    unsigned short a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 交換回数カウンタ
    unsigned short c = 0;

    // バブルソート
    bool iscontinue = true;
    while (iscontinue) {
        iscontinue = false;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] < a[i - 1]) {
                // swap a[i] and a[i - 1]
                unsigned short tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;

                // increment swap counter
                c++;

                iscontinue = true;
            }
        }
    }

    // 結果出力
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;

    cout << c << endl;

    return 0;
}

