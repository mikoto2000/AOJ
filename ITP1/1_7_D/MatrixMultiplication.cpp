#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // n, m, l を取得
    unsigned short n, m, l;
    cin >> n >> m >> l;

    unsigned short A[n][m];
    unsigned short B[m][l];
    unsigned long C[n][l];

    // 行列A を取得
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // 行列B を取得
    for (short i = 0; i < m; i++) {
        for (short j = 0; j < l; j++) {
            cin >> B[i][j];
        }
    }

    // 行列の掛け算
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < l; j++) {
            C[i][j] = 0;
            for (short k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 行列の表示
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < l - 1; j++) {
            cout << C[i][j] << " ";
        }
        cout << C[i][l - 1] << endl;
    }

    return 0;
}

