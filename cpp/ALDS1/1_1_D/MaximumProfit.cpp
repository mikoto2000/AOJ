#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 要素数を取得
    unsigned int n;
    cin >> n;

    // 計算のための初期値設定
    int minv;
    cin >> minv;
    int maxv = INT_MIN;

    // 計算主処理
    for (int j = 1; j < n; j++) {
        int r;
        cin >> r;

        cout << r - minv << endl;

        if ((r - minv) > maxv) {
            maxv = r - minv;
        }

        if (r < minv) {
            minv = r;
        }
    }

    // 標準出力
    cout << maxv << endl;

    return 0;
}

