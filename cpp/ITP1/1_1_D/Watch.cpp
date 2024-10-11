#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned int S;
    cin >> S;

    // 時・分の基数を定義
    const unsigned short MIN_BASE = 60;
    const unsigned short HOUR_BASE = 60;

    // 時・分・秒計算
    unsigned short s = S % MIN_BASE;
    unsigned short m = (S / MIN_BASE) % HOUR_BASE;
    unsigned short h = S / (MIN_BASE * HOUR_BASE);

    // 標準出力
    cout << h << ":" << m << ":" << s << endl;

    return 0;
}

