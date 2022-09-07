#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 数列 A の要素数 N を取得
    unsigned int n;
    cin >> n;

    // 数列の要素を取得
    unsigned int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unsigned long count = 0;
    for (int j = 0; j < n - 1; j++) {
        for (int i = j + 1; i < n; i++) {
            if (a[i] < a[j]) {
                count++;
            }
        }
    }

    // 標準出力
    cout << count << endl;

    return 0;
}

