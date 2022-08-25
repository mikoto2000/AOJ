#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 要素数を取得
    unsigned short n;
    cin >> n;

    // 各要素を取得
    unsigned short A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 交換回数カウンタ
    unsigned short c = 0;

    // 選択ソート
    for (unsigned short i = 0; i < n; i++) {
        unsigned short minj = i;
        for (unsigned short j = i; j < n; j++) {
            if ( A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            unsigned short tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            c++;
        }
    }

    // 結果表示
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;
    cout << c << endl;

    return 0;
}

