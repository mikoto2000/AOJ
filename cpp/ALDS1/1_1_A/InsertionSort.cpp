#include <iostream>

using namespace std;

void printA(short* A, short num) {

    for (short i = 0; i < num - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[num - 1] << endl;
}

int main(int argc, char* argv[]) {

    // 要素の数を取得
    short n;
    cin >> n;

    // 全要素を取得
    short A[n];
    for (short i = 0; i < n; i++) {
        cin >> A[i];
    }

    printA(A, n);

    // 挿入ソート実施
    for (short i = 1; i < n; i++) {
        short v = A[i];
        short j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printA(A, n);
    }

    return 0;
}

