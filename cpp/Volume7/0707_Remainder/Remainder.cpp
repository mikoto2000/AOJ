#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 数値の取得
    int x;
    cin >> x;

    // 21 で割った余りを計算
    int remainder = x % 21;

    // 結果表示
    cout << remainder << endl;

    return 0;
}

