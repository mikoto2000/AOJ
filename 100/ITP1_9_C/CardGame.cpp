#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // カードの枚数を取得
    int number;
    cin >> number;

    // スコア初期化
    int taro_score = 0;
    int hanako_score = 0;

    for (int i = 0; i < number; i++) {
        // カード情報取得
        string taro_card;
        cin >> taro_card;

        string hanako_card;
        cin >> hanako_card;

        // 得点計算
        int taro_compare_hanako = taro_card.compare(hanako_card);
        if (taro_compare_hanako == 0) {
            // 引き分け
            taro_score += 1;
            hanako_score += 1;
        } else if (taro_compare_hanako > 0) {
            // taro の勝ち
            taro_score += 3;
        } else {
            // taro の負け
            hanako_score += 3;
        }
    }

    // 結果出力
        cout << taro_score << " " << hanako_score << endl;

    return 0;
}

