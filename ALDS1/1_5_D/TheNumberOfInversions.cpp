#include <cstring>
#include <iostream>
#include <limits.h>

using namespace std;

unsigned long merge(unsigned int a[], unsigned int left, unsigned int mid, unsigned int right) {
    unsigned int left_array_size = mid - left;
    unsigned int right_array_size = right - mid;

    unsigned int left_array[left_array_size + 1];
    unsigned int right_array[right_array_size + 1];

    memcpy(left_array, &(a[left]), sizeof(unsigned int) * left_array_size);
    memcpy(right_array, &(a[mid]), sizeof(unsigned int) * right_array_size);

    left_array[left_array_size] = UINT_MAX;
    right_array[right_array_size] = UINT_MAX;

    unsigned long swap_count = 0;
    unsigned int li = 0;
    unsigned int ri = 0;
    for (int i = left; i < right; i++) {
        if (left_array[li] < right_array[ri]) {
            a[i] = left_array[li];
            li++;
        } else {
            // 左半分の要素数から、すでに a[] へ配置し終わったものの数を引くと、
            // 左要素と何個交換したかわかる。
            swap_count += left_array_size - li;

            a[i] = right_array[ri];
            ri++;
        }
    }

    return swap_count;
}

unsigned long merge_sort(unsigned int a[], unsigned int left, unsigned int right) {

    if (!(left + 1 < right)) return 0;

    unsigned int mid = (left + right) / 2;

    unsigned long swap_count = 0;
    // 左半分
    swap_count += merge_sort(a, left, mid);

    // 右半分
    swap_count += merge_sort(a, mid, right);

    // マージ
    swap_count += merge(a, left, mid, right);

    return swap_count;
}

int main(int argc, char* argv[]) {

    // 数列 A の要素数 N を取得
    unsigned int n;
    cin >> n;

    // 数列の要素を取得
    unsigned int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 反転数の数は、バブルソートの交換回数に等しい。
    // バブルソートでは TLE してしまうので、
    // 代わりにマージソートで交換回数を数える。
    unsigned long swap_count = merge_sort(a, 0, n);

    // 標準出力
    cout << swap_count << endl;

    return 0;
}

