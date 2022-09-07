#include <cstring>
#include <iostream>

#define MAX_VALUE 10000

using namespace std;

void counting_sort(unsigned short a[],unsigned short b[], unsigned int n, unsigned int k) {
    unsigned int c[k + 1];

    // 配列 C をゼロで初期化
    memset(c, 0, sizeof(unsigned int) * k + 1);

    // c[i] に、配列 A 内に数値 i が出現した回数を記録
    for (unsigned int i = 0; i < n; i++) {
        c[a[i]]++;
    }

    // c[i] に i 以下の数の出現回数を記録
    for (unsigned int i = 1; i < k; i++) {
        c[i] = c[i] + c[i - 1];
    }

    // 配列 C を基に、配列 B へ数字を格納
    for (long i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
}

int main(int argc, char* argv[]) {

    // 数列 A のサイズを取得
    unsigned int n;
    cin >> n;

    // 数列 A の数値を取得
    unsigned short a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 配列 B を作成し、 Counting Sort を実施
    unsigned short b[n];
    counting_sort(a, b, n, MAX_VALUE);

    // 標準出力
    for (int i = 0; i < n - 1; i++) {
        cout << b[i] << " ";
    }
    cout << b[n - 1] << endl;

    return 0;
}

