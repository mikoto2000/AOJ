#include <iostream>

using namespace std;

bool isOk(unsigned int n, unsigned int k, unsigned int w[], unsigned int p) {

    unsigned int current_truck = 1;
    unsigned int current_truck_weight = 0;
    for (int i = 0; i < n; i++) {
        // 荷物が詰めるかの判定 その１
        if (w[i] > p) {
            // そもそもトラックに入らない荷物がある
            return false;
        }

        // 荷物が詰めるかの判定 その２
        if (current_truck_weight + w[i] > p) {
            current_truck++;
            current_truck_weight = 0;

            if (current_truck > k) {
                // すべてのトラックを使っても入りきらなかった
                return false;
            }
        }

        // 荷物を積み込む
        current_truck_weight += w[i];
    }

    // すべての荷物が載りきった
    return true;
}

int main(int argc, char* argv[]) {

    // 荷物の数 n とトラックの数 k を取得
    unsigned int n, k;
    cin >> n >> k;

    // 荷物情報の取得と、合計計算
    unsigned int w[n];
    unsigned long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    unsigned int avg = sum / n;

    // 平均から最大までを 2 分探索
    long left = avg;
    long right = sum;
    long current = left + (right - left) / 2;
    long min_ok = 100001;

    while (left <= right) {
        if (isOk(n, k, w, current)) {
            min_ok = current;

            // もっと小さいのを探す
            right = current - 1;
            current = (left + right) / 2;
        } else {

            // もっと大きいのを探す
            left = current + 1;
            current = (left + right) / 2;
        }
    }

    cout << min_ok << endl;

    return 0;
}

