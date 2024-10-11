#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>

#define deg_to_rad(deg) (((deg)/360.0)*2.0*M_PI)
#define rad_to_deg(rad) (((rad)/2.0/M_PI)*360.0)

using namespace std;

pair<double, double> rotate(double p1x, double p1y, double p2x,double p2y, double theta_radian) {
    double rotated_x = ((p2x - p1x) * cos(theta_radian)) - ((p2y - p1y) * sin(theta_radian)) + p1x;
    double rotated_y = ((p2x - p1x) * sin(theta_radian)) + ((p2y - p1y) * cos(theta_radian)) + p1y;

    return make_pair(rotated_x, rotated_y);
}

void do_koch(list<pair<double, double>> &points, unsigned short count) {
    if (count == 0) {
        return;
    }

    // points で定義される線分すべてにコッホ曲線処理を行う
    for (auto it = points.begin(), e = prev(points.end()); it != e; ) {
        auto next_point = next(it, 1);

        double p1x = it->first;
        double p1y = it->second;

        double p2x = next_point->first;
        double p2y = next_point->second;

        // 与えられた線分を 3 等分し、分割した点を s, t とする
        double sx = (2.0 * p1x + p2x) / 3;
        double sy = (2.0 * p1y + p2y) / 3;
        double tx = (p1x + 2 * p2x) / 3;
        double ty = (p1y + 2 * p2y) / 3;

        // s, t を頂点とする正三角形 (s, u, t) を作成したときの、 t の座標を求める
        auto u = rotate(sx, sy, tx, ty, deg_to_rad(60));

        // 求めた点をリストに挿入する
        points.insert(next_point, make_pair(sx, sy));
        points.insert(next_point, u);
        points.insert(next_point, make_pair(tx, ty));

        it = next_point;
    }

   do_koch(points,  --count);
}

int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned short n;
    cin >> n;

    // 初期の視点終点を定義
    list<pair<double, double>> points;
    points.push_back(make_pair(0, 0));
    points.push_back(make_pair(100, 0));

    do_koch(points, n);

    cout << std::fixed;
    for (auto point : points) {
        cout << setprecision(4) << point.first << " " << point.second << endl;
    }

    return 0;
}

