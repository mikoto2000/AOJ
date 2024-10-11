#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // r, c を取得
    unsigned int r, c;
    cin >> r >> c;

    // 表の初期化
    unsigned int result[r + 1][c + 1];
    for (short i = 0; i < r + 1; i++) {
       result[i][c] = 0;
    }
    for (short i = 0; i < c + 1; i++) {
       result[r][i] = 0;
    }

    // 表の情報取得
    for (short i = 0; i < r; i++) {
        for (short j = 0; j < c; j++) {
            cin >> result[i][j];

            // 列合計更新
            result[r][j] += result[i][j];

            // 行合計更新
            result[i][c] += result[i][j];

            // 全要素の合計更新
            result[r][c] += result[i][j];
        }
    }

    // 表の出力
    for (short i = 0; i < r + 1; i++) {
        for (short j = 0; j < c; j++) {
            cout << result[i][j]  << " ";
        }
        cout << result[i][c] << endl;
    }

    return 0;
}

