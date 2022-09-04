#include <cstring>
#include <iostream>
#include <limits.h>

using namespace std;

unsigned int comp_count = 0;

void merge(unsigned int s[], unsigned int left, unsigned int mid, unsigned int right) {

    // 右半分と左半分をそれぞれ別配列にコピー
    unsigned int left_array_size = mid - left;
    unsigned int right_array_size = right - mid;

    unsigned int left_array[left_array_size + 1];
    unsigned int right_array[right_array_size + 1];

    memcpy(left_array, &(s[left]), left_array_size * sizeof(unsigned int));
    memcpy(right_array, &(s[mid]), right_array_size * sizeof(unsigned int));

    // 左右どちらかにしか要素がなかった場合に備えて、
    // どの要素よりも必ず大きくなる要素を配列末尾に入れておく
    left_array[left_array_size] = UINT_MAX;
    right_array[right_array_size] = UINT_MAX;

    // 左右の配列の先頭要素を比較しながら s[] に書き戻すことでソートを実施
    unsigned int left_index = 0;
    unsigned int right_index = 0;
    for (int i = left; i < right; i++) {

        // 比較回数をインクリメント
        comp_count++;

        // 左右の配列の先頭同士を比較し、小さいほうを s[] に書き戻す
        if (left_array[left_index] <= right_array[right_index]) {
            s[i] = left_array[left_index];
            left_index++;
        } else {
            s[i] = right_array[right_index];
            right_index++;
        }
    }
}


void merge_sort(unsigned int s[], unsigned int left, unsigned int right) {
    if (left + 1 < right) {
        // left と right の中心を計算
        unsigned int mid = (left + right) / 2;

        // 左半分を処理
        merge_sort(s, left, mid);

        // 右半分を処理
        merge_sort(s, mid, right);

        // 左右をマージ
        merge(s, left, mid, right);
    }
}

int main(int argc, char* argv[]) {

    // 数列 S の数を取得
    unsigned int n;
    cin >> n;

    // 数列 S を取得
    unsigned int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    merge_sort(s, 0, n);

    // ソート結果を出力
    for (int i = 0; i < n - 1; i++) {
        cout << s[i] << " ";
    }
    cout << s[n - 1] << endl;

    // 比較数を出力
    cout << comp_count << endl;

    return 0;
}

