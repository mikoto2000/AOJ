#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char* argv[]) {

    // 出力する高番号 n を取得
    unsigned short n;
    cin >> n;

    // 結果出力
    cout << fib(n) << endl;

    return 0;
}

