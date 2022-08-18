#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    // 単語 W を取得
    string w;
    getline(cin, w);
    w = " " + w + " ";

    // 文章 T を取得
    string t;
    while (true) {
        // 標準入力を一行取得
        string line;
        getline(cin, line);

        // 文章の終わり(`END_OF_TEXT`)チェック
        if (line == "END_OF_TEXT") {
            // 文章の終わりの場合、文章 T 取得ループを抜ける
            break;
        } else {
            // 文章の終わりでない場合、文章 T 変数に入力文字列を追加
            // マッチ簡単化のため、 line の前後に半角スペースを追加。
            // これで、「単語 W の前後に半角スペース」にマッチする文字列を数えれば OK になる。
            t.append(" ");
            t.append(line);
            t.append(" ");
        }
    }

    // 文章 T のすべての文字を小文字に変換
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);

    // 文章 T 内の単語 W を数える
    int count = 0;
    int find_start_position = 0;
    while ((find_start_position = t.find(w, find_start_position)) != string::npos) {
        count++;
        find_start_position++;
    }

    // カウント結果を出力
    cout << count << endl;

    return 0;
}

