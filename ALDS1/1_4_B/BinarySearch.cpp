#include <iostream>

using namespace std;

bool binary_search_internal(
        const unsigned int left,
        const unsigned int right,
        const unsigned int s[],
        const unsigned int target) {
    unsigned int center = (left + right) / 2;

    if (s[center] == target) {
        return true;
    }

    if (left >= right) {
        return false;
    }

    unsigned int new_left, new_right;
    if (s[center] < target) {
        new_left = center + 1;
        new_right = right;
    } else {
        new_left = left;
        new_right = center - 1;
    }

    return binary_search_internal(new_left, new_right, s, target);

}

bool binary_search(const unsigned int n, const unsigned int s[], const unsigned int target) {
    unsigned int left = 0;
    unsigned int right = n - 1;

    return binary_search_internal(left, right, s, target);
}

int main(int argc, char* argv[]) {

    // 数列 S の要素の数を取得
    unsigned int n;
    cin >> n;

    // S の要素を取得
    unsigned int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // 数列 T の要素の数を取得
    unsigned int q;
    cin >> q;

    // T の要素を取得
    unsigned int t[q];
    for (int i = 0; i < q; i++) {
        cin >> t[i];
    }

    // T の要素が S に含まれているかをチェック
    unsigned int count = 0;
    for (int i = 0; i < q; i++) {
        if (binary_search(n, s, t[i])) {
            count++;
        }
    }

    // 標準出力
    cout << count << endl;

    return 0;
}

