#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    /**
     * 前提:
     *     - 辺 a, b が繋がっている点を原点とする
     *     - 辺 a は、角度 0 の方向に伸びているものとする
     **/

    // 標準入力を取得
    double a_len, b_len, c_degree;
    cin >> a_len >> b_len >> c_degree;

    // 辺 a の原点でない方の点位置
    double a_pos_x2 = a_len;
    double a_pos_y2 = 0;

    // 角度 θ を degree から radian に変換
    double c_radian = c_degree * (M_PI/180.0);

    // 長さと角度から b 原点でない方の座標を計算
    double b_pos_x2 = b_len * cos(c_radian);
    double b_pos_y2 = b_len * sin(c_radian);

    // a を底辺としたときの高さ取得
    double h = b_pos_y2;

    // 面積計算
    double s = (a_len * b_pos_y2) / 2.0;

    // 周の長さ計算
    double c_len = sqrt(
        pow(a_pos_x2 - b_pos_x2, 2) + pow(a_pos_y2 - b_pos_y2, 2)
    );
    double l = a_len + b_len + c_len;

    // 結果出力
    cout << std::fixed;
    cout << setprecision(4) << s << endl;
    cout << setprecision(4) << l << endl;
    cout << setprecision(4) << h << endl;

    return 0;
}

