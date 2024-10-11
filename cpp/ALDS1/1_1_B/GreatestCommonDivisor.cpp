#include <iostream>

using namespace std;

long gcd(long x, long y) {
    // 大小判定
    long lt, gt;
    if (x >= y) {
        gt = x;
        lt = y;
    } else {
        gt = y;
        lt = x;
    }

    // 小さいほうがゼロなら、両方で割り切れているという事
    if (lt == 0) {
        return gt;
    }

    // そうでないなら再帰処理
    return gcd(lt, gt % lt);

}

int main(int argc, char* argv[]) {

    // x, y を取得
    long x, y;
    cin >> x >> y;

    // x, y の最大公約数を計算
    cout << gcd(x, y) << endl;

    return 0;
}

