/**
 * See: https://ikapblg.blog.fc2.com/blog-entry-56.html
 */
#include <algorithm>
#include <iostream>

using namespace std;

string split(short n, short pre[], short in[], short left, short right) {
    // 葉まで行ったら結果を返却
    if (left == right) {
        return to_string(in[left]);
    }

    // pre の配列の中で、一番早く in の範囲内の番号が出現する index が、部分木の根になる
    short min_index = 41;
    for (int i = left; i <= right; i++) {
        auto it = find(pre, pre + n, in[i]);
        auto index = distance(pre, it);
        if (index < min_index) min_index = index;
    }

    // 部分木の根が、 in 配列内のどの index になっているか確認
    short current_root_value = pre[min_index];
    auto middle_it = find(in + left, in + right, current_root_value);
    auto middle = distance(in, middle_it);


    // 再帰的に左・右・middle と結合することで、後方巡回の順序で数値を結合
    string str = "";

    if (middle - 1 >= left) {
        // 左半分再帰
        str += split(n, pre, in, left, middle - 1);
    }

    if (middle + 1 <= right) {
        if (str != "") {
            str += " ";
        }
        // 右半分再帰
        str += split(n, pre, in, middle + 1, right);
    }

    if (str != "") {
        str += " ";
    }
    str += to_string(in[middle]);

    return str;

}

int main(int argc, char* argv[]) {

    // ノードの数 N を取得
    short n;
    cin >> n;

    // 先行巡回の配列を取得
    short pre[n];
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    // 中間巡回の配列を取得
    short in[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    // 部分木に、再帰的に分割していく
    string result = split(n, pre, in, 0, n - 1);

    // 標準出力
    cout << result << endl;

    return 0;
}

