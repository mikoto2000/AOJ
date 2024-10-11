#include <iostream>

using namespace std;

void suffle(string cards);

int main(int argc, char* argv[]) {

    while(true) {
        // カードの山を取得
        string cards;
        cin >> cards;

        // データセットの終わり(`-`)チェック
        if (cards == "-") {
            // データセットの終わりの場合、終了
            break;
        } else {
            // データセットの終わりでない場合、シャッフル操作実行
            suffle(cards);
        }
    }

    return 0;
}

void suffle(string cards) {
    // シャッフル回数を取得
    int count;
    cin >> count;

    // シャッフル操作ループ
    for (int i = 0; i < count; i++) {

        // シャッフル操作の枚数 h を取得
        int number;
        cin >> number;

        // シャッフル操作実行
        string head = cards.substr(0, number);
        string tail = cards.substr(number, cards.length());
        cards = tail + head;
    }

    cout << cards << endl;
}

