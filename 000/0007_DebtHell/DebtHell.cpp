#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 借金の初期値 100,000
    double borrowing = 100000;

    // n 週間を取得
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        // 利子計算
        borrowing = borrowing * 1.05;

        // 1,000 未満切り上げ
        borrowing = borrowing / 1000;
        borrowing = ceil(borrowing);
        borrowing = borrowing * 1000;
    }

    // 結果表示
    cout << (int)borrowing << endl;

    return 0;
}

