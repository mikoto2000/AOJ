#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 数値の数を取得
    unsigned short num_count;
    cin >> num_count;

    // min, max, sum の初期値設定
    int min = INT_MAX;
    int max = INT_MIN;
    long sum = 0;

    for (short i = 0; i < num_count; i++) {
        // 数値取得
        int number;
        cin >> number;

        // 最小値判定
        if (number < min) {
            min = number;
        }

        // 最大値判定
        if (number > max) {
            max = number;
        }

        // 合計計算
        sum += number;
    }

    // 標準出力
    cout << min << " " << max << " " << sum << endl;

    return 0;
}

