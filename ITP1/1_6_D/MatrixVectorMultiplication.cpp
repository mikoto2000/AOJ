#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // m,n を取得
    unsigned int n, m;
    cin >> n >> m;

    // 行列を取得
    unsigned short matrixA[n * m];
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            cin >> matrixA[i * m + j];
        }
    }

    // ベクトルを取得
    unsigned short vectorB[m];
    for (short i = 0; i < m; i++) {
        cin >> vectorB[i];
    }

    // 積の計算
    unsigned int resultC[n];
    for (short i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++) {
            sum += matrixA[i * m + j] * vectorB[j];
        }
        
        resultC[i] = sum;
    }

    // 結果表示
    for (short i = 0; i < n; i++) {
        cout << resultC[i] << endl;
    }

    return 0;
}

