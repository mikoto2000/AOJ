#include <iostream>

using namespace std;

void insertionSort(unsigned int a[], unsigned int n, unsigned int g, unsigned int *cnt) {
    for (int i = g; i < n; i++) {
        unsigned int v = a[i];
        long j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j+g] = a[j];
            j = j - g;
            (*cnt)++;
        }
        a[j+g] = v;
    }
}

void shellSort(unsigned int a[], unsigned int n, unsigned int *cnt) {
    unsigned int m = 2;
    unsigned int g[100];
    g[0] = 1
    g[1] = 2
    for (int i = 2; i < 100; i++) {
        g[i] = g[i - 1] * 2;
    }

    for (int i = 0; i < m; i++) {
        insertionSort(a, n, g[i], cnt);
    }

}

int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned int n;
    cin >> n;

    // 各要素を取得
    unsigned int a[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unsigned int cnt = 0;
    shellSort(a, n, &cnt);

    // 標準出力
    cout << 2 << endl;
    cout << "4 1" << endl;
    cout << cnt << endl;
    for (unsigned int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}

