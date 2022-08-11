#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // 数値の取得
    int number;

    while(cin >> number) {
        // 組み合わせ数初期化
        int count = 0;

        // 全パターンをテスト
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    for (int l = 0; l < 10; l++) {
                        if (i + j + k + l == number) {
                            count++;
                        }
                    }
                }
            }
        }

        // 結果表示
        cout << count << endl;
    }

    return 0;
}

