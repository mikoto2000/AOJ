#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    while (true) {
        // データセット内のデータ数を取得
        short n;
        cin >> n;

        // 終了判定
        // n == 0 の場合を入力の終わりとする
        if (n == 0) {
            return 0;
        }

        // データの取得と合計計算
        double ss[n];
        double sum = 0;
        for (short i = 0; i < n; i++) {
            cin >> ss[i];
            sum += ss[i];
        }
        double average = sum / (double)n;

        // 分散の計算
        double tmp = 0;
        for (short i = 0; i < n; i++) {
            tmp += pow((ss[i] - average), 2);
        }
        double variance = tmp / (double)n;

        // 標準偏差の計算
        double sd = sqrt(variance);

        // 結果の表示
        cout << std::fixed;
        cout << setprecision(4) << sd << endl;
    }
}

