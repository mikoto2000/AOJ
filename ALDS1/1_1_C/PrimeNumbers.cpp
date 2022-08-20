#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(long v) {
    // 1 以下の判定
    if (v < 2) {
        return false;
    }

    // 2 の判定
    if (v == 2) {
        return true;
    }

    long sqrtv = sqrt(v);

    for (long i = 2; i <= sqrtv; i++) {
        if (v % i == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {

    // 要素の数を取得
    short n;
    cin >> n;

    short prime_count = 0;
    for (int i = 0; i < n; i++) {
        // 与えられた整数を取得
        long v;
        cin >> v;

        // 素数確認
        if (is_prime(v)) {
            prime_count++;
        }
    }

    // 標準出力
    cout << prime_count << endl;

    return 0;
}

