#include <algorithm>
#include <iostream>

using namespace std;

unsigned int partition(unsigned int a[], unsigned int p, unsigned int r) {
    unsigned int x = a[r];

    unsigned int i = p - 1;

    for (int j = p; j < r; j++) {
        if (a[j] <= x) {
            i = i + 1;
            // A[i] と A[j] を交換
            swap(a[i], a[j]);
        }
    }

    // A[i + 1] と A[r - 1] を交換
    swap(a[i + 1], a[r]);

    return i + 1;
}

int main(int argc, char* argv[]) {

    // 数列 A の要素数 N を取得
    unsigned int n;
    cin >> n;

    // 数列 A を取得
    unsigned int a[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unsigned int pat = partition(a, 0, n - 1);

    // 標準出力
    for (unsigned int i = 0; i < n - 1; i++) {
        if (i == pat) {
            cout << "[" << a[i] << "] ";
        } else {
            cout << a[i] << " ";
        }
    }
    if (n - 1 == pat) {
        cout << "[" << a[n - 1] << "]" << endl;
    } else {
        cout << a[n - 1] << endl;
    }

    return 0;
}

