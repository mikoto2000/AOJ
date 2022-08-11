#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // P1, P2 の座標を取得
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double distance = sqrt(
        pow(x2 - x1, 2) + pow(y2 - y1, 2)
    );

    // 結果出力
    cout << std::fixed;
    cout << setprecision(4) << distance << endl;

    return 0;
}

