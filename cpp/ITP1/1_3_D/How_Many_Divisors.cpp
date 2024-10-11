#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned short a, b, c;
    cin >> a >> b >> c;

    // a から b までの数字内の、 c を割り切れるをカウント
    unsigned short count = 0;
    for (short i = a; i <= b; i++) {
        if (c % i == 0) {
            count++;
        }
    }

    // 標準出力
    cout << count << endl;

    return 0;
}

