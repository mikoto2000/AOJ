#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned short W, H, r;
    short x, y;
    cin >> W >> H >> x >> y >> r;

    // 判定して出力
    if (x + r > W // 右辺判定
            || x - r < 0 // 左辺判定
            || y + r > H // 上辺判定
            || y - r < 0 // 下辺判定
    ) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

