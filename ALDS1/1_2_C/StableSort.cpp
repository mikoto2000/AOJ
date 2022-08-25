#include <iostream>

using namespace std;

// バブルソート
void bubble_sort(string a[], short n) {
    bool iscontinue = true;
    while (iscontinue) {
        iscontinue = false;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i][1] < a[i - 1][1]) {
                string tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                iscontinue = true;
            }
        }
    }
}

// 選択ソート
void selection_sort(string a[], unsigned short n) {
    for (unsigned short i = 0; i < n; i++) {
        unsigned short minj = i;
        for (unsigned short j = i; j < n; j++) {
            if ( a[j][1] < a[minj][1]) {
                minj = j;
            }
        }
        if (i != minj) {
            string tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
        }
    }
}


int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned short n;
    cin >> n;

    // 各要素を取得
    string b[n], s[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s[i] = b[i];
    }

    // バブルソート
    bubble_sort(b, n);

    // 選択ソート
    selection_sort(s, n);

    // バブルソート結果出力
    for (int i = 0; i < n - 1; i++) {
        cout << b[i] << " ";
    }
    cout << b[n - 1] << endl;
    // バブルソートは安定ソートなので必ず Stable
    cout << "Stable" << endl;

    // 選択ソート結果出力
    bool is_stable = true;
    for (int i = 0; i < n - 1; i++) {
        cout << s[i] << " ";
        if (s[i] != b[i]) {
            is_stable = false;
        }
    }
    cout << s[n - 1] << endl;
    if (is_stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}

