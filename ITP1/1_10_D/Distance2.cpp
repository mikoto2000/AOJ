#include <cmath>
#include <float.h>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // ベクトルの次元数を取得
    short n;
    cin >> n;

    // ひとつ目のベクトル取得
    short x[n];
    for (short i = 0; i < n; i++) {
        cin >> x[i];
    }

    // ふたつ目のベクトル取得
    short y[n];
    for (short i = 0; i < n; i++) {
        cin >> y[i];
    }

    // 各距離計算
    double manhattan_distance = 0;
    double euclidean_distance = 0;
    double chebyshev_distance = DBL_MIN;
    double p_3_distance = 0;
    for (short i = 0; i < n; i++) {
        // 差の絶対値
        double sub_abs = abs(x[i] - y[i]);

        manhattan_distance += sub_abs;

        euclidean_distance += pow(sub_abs, 2.0);

        p_3_distance += pow(sub_abs, 3.0);

        if (sub_abs > chebyshev_distance) {
            chebyshev_distance = sub_abs;
        }
    }
    euclidean_distance = sqrt(euclidean_distance);
    p_3_distance = pow(p_3_distance, 1.0/3.0);

    // 標準出力
    cout << std::fixed;
    cout << setprecision(5) << manhattan_distance << endl;
    cout << setprecision(5) << euclidean_distance << endl;
    cout << setprecision(5) << p_3_distance << endl;
    cout << setprecision(5) << chebyshev_distance << endl;

    return 0;
}

