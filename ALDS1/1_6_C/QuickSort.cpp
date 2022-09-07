#include <iostream>
#include <tuple>

using namespace std;

unsigned int partition(tuple<char, unsigned int, unsigned int> a[], unsigned int p, unsigned int r) {
    unsigned int x = get<1>(a[r]);

    unsigned int i = p - 1;

    for (int j = p; j < r; j++) {
        if (get<1>(a[j]) <= x) {
            i = i + 1;
            // A[i] と A[j] を交換
            swap(a[i], a[j]);
        }
    }

    // A[i + 1] と A[r - 1] を交換
    swap(a[i + 1], a[r]);

    return i + 1;
}

void quick_sort(tuple<char, unsigned int, unsigned int> a[], unsigned int q, unsigned int p, unsigned int r) {
    if (p < r) {
        q = partition(a, p, r);
        quick_sort(a, q, p, q - 1);
        quick_sort(a, q, q + 1, r);
    }
}

int main(int argc, char* argv[]) {

    // カードの枚数 n を取得
    unsigned int n;
    cin >> n;

    // カード情報を取得
    tuple<char, unsigned int, unsigned int> a[n];
    for (unsigned int i = 0; i < n; i++) {
        char suit;
        unsigned int num;
        cin >> suit >> num;
        a[i] = make_tuple(suit, num, i);
    }

    quick_sort(a, n - 1, 0, n - 1);

    // 出力が安定だったかを判定
    bool is_stable = true;
    for (int i = 0; i < n - 1; i++) {

        // 数値が等しい場合は、 id で比較
        // 左より右の要素の id が大きければ安定
        if (get<1>(a[i]) == get<1>(a[i + 1])
                && (get<2>(a[i]) > get<2>(a[i + 1]))) {
            is_stable = false;
            break;
        }
    }

    // 安定かどうかの出力
    if (is_stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    // ソート後のカード情報を出力
    for (int i = 0; i < n; i++) {
        cout << get<0>(a[i]) << " " << get<1>(a[i]) << endl;
    }

    return 0;
}

