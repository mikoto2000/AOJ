#include <iostream>

using namespace std;

bool isOk_internal(
        unsigned short n,
        unsigned short a[],
        unsigned short m,
        unsigned short current_index,
        unsigned short sum) {
    // 組み合わせで m を実現できるかチェック
    if (sum == m) {
        return true;
    }

    // sum が m を超えていたら実現不可能だったという事
    if (sum > m) {
        return false;
    }

    // current_index が n を超えていたら、実現不可能だったという事
    if (current_index >= n) {
        return false;
    }

    // current_index を足した場合に m を実現できるか確認
    unsigned short next_index = current_index + 1;
    if (isOk_internal(n, a, m, next_index, sum + a[current_index])) {
        // current_index を足した場合に実現できた
        return true;
    } else {
        // current_index を足した場合に実現できなかったので、
        // current_index を足さない場合を確認
        return isOk_internal(n, a, m, next_index, sum);
    }
}

// 数列 A の各要素を足した場合・足さなかった場合を、深さ優先探索で探索。
bool isOk(unsigned short n, unsigned short a[], unsigned short m) {
    return isOk_internal(n, a, m, 0, 0);
}

int main(int argc, char* argv[]) {

    // 数列 A の要素数 n を取得
    unsigned short n;
    cin >> n;

    // 数列 A の要素を取得
    unsigned short a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // m の数 q を取得
    unsigned short q;
    cin >> q;

    // m 毎に、数列 A の組み合わせで実現可能かを確認する
    for (int i = 0; i < q; i++) {
        // m を取得
        unsigned short m;
        cin >> m;

        // 数列 A　の組み合わせで m が実現可能かを判定
        if (isOk(n, a, m)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}

