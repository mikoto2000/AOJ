/**
 * See: https://qiita.com/_rdtr/items/c49aa20f8d48fbea8bd2
 */
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

unsigned short lcs(string x, string y) {

    // x[0] から x[i] までと、 y[0] から y[j] までの
    // 最長共通部分列の長さを記録する 2 次元配列を作成
    // 「空文字 + 各文字」の分だけ領域を確保
    int x_length = x.size() + 1;
    int y_length = y.size() + 1;
    int m[x_length][y_length];
    memset(m, 0, sizeof(int) * x_length * y_length);

    // 空文字部分はゼロ固定なので飛ばして、
    // 一文字目から最長共通部分列を探していく
    for (int i = 1; i < x_length; i++) {
        for (int j = 1; j < y_length; j++) {
            int x_index = i - 1;
            int y_index = j - 1;
            //cout << x[x_index] << " " << y[y_index] << endl;

            if (x[x_index] == y[y_index]) {
                // 等しい文字が見つかったら、
                // x, y 共に一文字短い場合の lcs にプラス 1 したものが
                // m[i][j] の lcs になる
                m[i][j] = m[i - 1][j - 1] + 1;
            } else {
                // 等しくなければ、
                // x が一文字短い場合と y が一文字短い場合の lcs を比べて
                // 大きい方が m[i][j] の lcs になる
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }

    // 一番右下の要素が全体の lcs なのでこれをリターン
    return m[x_length - 1][y_length - 1];
}

int main(int argc, char* argv[]) {

    // データセットの数 q を取得
    unsigned short q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        // 文字列 X, Y を取得
        string x, y;
        cin >> x >> y;

        cout << lcs(x, y) << endl;

    }

    return 0;
}

