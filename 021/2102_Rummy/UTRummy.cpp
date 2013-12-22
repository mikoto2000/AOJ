#include <algorithm>
#include <iostream>
#include <stdio.h>

#define DEAL_CARD_NUM 9
#define RESULT_TRUE 1
#define RESULT_FALSE 0

using namespace std;

/**
 * カードクラス
 *
 * カードの色と数字を管理する。
 */
class Card {
    private:
        char color;
        int number;
    public:
        Card();
        Card* init(char color, int number);
        char getColor() const;
        int getNumber() const;
        bool operator < (const Card& oth) const;
        bool operator == (const Card& oth) const;
};

/**
 * コンストラクタ
 *
 * 今回は静的に配列を確保したかったので、
 * 引数なしのコンストラクタと初期化関数の
 * 組み合わせ方式を採用。
 */
Card::Card() {
}

/**
 * 初期化関数
 *
 * 今回は静的に配列を確保したかったので、
 * 引数なしのコンストラクタと初期化関数の
 * 組み合わせ方式を採用。
 */
Card* Card::init(char color, int number) {
    this->color = color;
    this->number = number;
    return this;
}

/**
 * カードの色を取得。
 */
char Card::getColor() const {
    return this->color;
}

/**
 * カードの数字を取得。
 */
int Card::getNumber() const {
    return this->number;
}

/**
 * カードソート用関数。
 * 
 * 色の昇順, 数字の昇順 の組み合わせでソート。
 */
bool Card::operator < (const Card& oth) const {
    if (this->getColor() < oth.getColor()) {
        return true;
    } else if (this->getColor() > oth.getColor()) {
        return false;
    } else {
        return this->getNumber() < oth.getNumber();
    }
}

/**
 * カード比較用関数。
 * 
 * 色と数字が一致すれば等しいと判断する。
 */
bool Card::operator == (const Card& oth) const {
    return this->getColor() == oth.getColor()
            && this->getNumber() == oth.getNumber();
}

/**
 * カードの役判定を行う抽象クラス。
 * TODO : せっかく約判定を切り替えられるように作成したが、
 *        これだと「役かどうか」歯科判定できない。
 *        それってあまり嬉しくない気がするので、
 *        戻り値は int とか
 *        「役コード」を返せるようにすべきではないかな？
 */
class Rule {
    public:
        virtual bool isPod(size_t size, Card cards[]) = 0;
};

/**
 * カードの役判定クラス。
 * AOJ の問題条件で判定する。
 */
class DefaultRule : public Rule {
    private:
        static const int CARD_NUM = 9;
        static const int SET_CARD_NUM = 3;
        bool containSet(size_t size, Card cards[]);
    public:
        /** カード配列の役判定 */
        bool isPod(size_t size, Card cards[]);
};

/**
 * 指定されたカード配列が、役になっているかを確認する。
 *
 * @param size カード配列のサイズ
 * @param cards カード配列
 * @return 判定結果(true:役になっている, false:役になっていない)
 */
bool DefaultRule::isPod(size_t size, Card cards[]) {
    // cards が 9 枚であることを確認する
    if (size != DefaultRule::CARD_NUM) {
        return false;
    }

    // 役判定を行う
    return containSet(size, cards);
}

/**
 * 指定されたカード配列の中に、
 * セットの条件を満たす組が存在するかを確認する。
 * この関数が呼ばれる時点で、
 * カードの枚数についての条件下クリアしていることが前提。
 * よって、カード枚数チェックなどは行わない。
 *
 * @param size カード配列のサイズ
 * @param cards カード配列
 * @return 判定結果(true:セット条件を満たす組がある, false:セット条件を満たす組が無い)
 */
bool DefaultRule::containSet(size_t size, Card cards[]) {

    // size が 0 という事は、
    // セットに出来る組み合わせが全て揃ったということなので
    // true を返す。
    if (size == 0) {
        return true;
    }

    // 先頭 3 枚が同じ色か確認する
    if (!(cards[0].getColor() == cards[1].getColor()
            && cards[1].getColor() == cards[2].getColor())) {
        // 最低限同じ色が 3 枚揃わないと役にならないので、
        // 同じ色が 3 枚揃わない時点で強制終了する。
        return false;
    }

    // 先頭 3 枚が同じ数であるかを確認する
    if (cards[0].getNumber() == cards[1].getNumber()
            && cards[1].getNumber() == cards[2].getNumber()) {

        // 先頭 3 枚が同じ数であれば、
        // それらより後ろの要素を使って再帰処理。
        return containSet(size - DefaultRule::SET_CARD_NUM, cards + DefaultRule::SET_CARD_NUM);
    } else {
        // 先頭 3 枚が同値でなければ、
        // 3 枚の連番が作れるか確認する
        // cards[0] + 1 の要素のインデックス番号
        int p1 = 0;
        // cards[0] + 2 の要素のインデックス番号
        int p2 = 0;
        for (int i = 1; i < size; i++) {
            // 色違いになったらもう望みはない。
            if (cards[i].getColor() != cards[0].getColor()) {
                break;
            }

            // 連番になれる要素のインデックス番号を記録する。
            if (cards[i].getNumber() == cards[0].getNumber() + 1) {
                p1 = i;
            } else if (cards[i].getNumber() == cards[0].getNumber() + 2) {
                p2 = i;
            }
        }

        // p1 と p2 どちらかが 0 であれば、
        // 連番が見つからなかったという事。
        if (p1 == 0 || p2 == 0) {
            return false;
        }

        // 連番が作成できる組み合わせを削除し、再帰処理。
        int newSize = size - DefaultRule::SET_CARD_NUM;

        // 新配列と旧配列のインデックスの差を記録する
        int offset = 1;

        Card newCards[newSize];
        for (int i = 1; i <= size; i++) {
            // セットの要素になったものは無視する
            if (i == p1 || i == p2) {
                offset++;
                continue;
            }

            // 旧配列から新配列に詰め替える
            newCards[i - offset] = cards[i];
        }

        return containSet(newSize, newCards);
    }
}

/**
 * 標準入力から手札情報を取得し、deal に設定する
 *
 * @param deal 手札情報(out)
 */
void setDeal(Card deal[]) {
    int numbers[DEAL_CARD_NUM];
    char colors[DEAL_CARD_NUM];

    // 手札の数値情報を取得する
    for (int j = 0; j < DEAL_CARD_NUM; j++) {
        cin >> numbers[j];
    }

    // 手札の色情報を取得する
    for (int j = 0; j < DEAL_CARD_NUM; j++) {
        cin >> colors[j];
    }

    // 取得した、数値・色情報をから
    // Card オブジェクトを作成する
    for (int j = 0; j < DEAL_CARD_NUM; j++) {
        deal[j].init(colors[j], numbers[j]);
    }
}

int main(int argc, char** argv) {

    // 判定する手札の数を取得
    int gameNum;
    cin >> gameNum;

    // 今回使うルールを準備
    Rule* rule = new DefaultRule();

    // 判定する手札の数だけ繰り返す
    for (int i = 0; i < gameNum; i++) {

        // 手札の準備
        Card deal[DEAL_CARD_NUM];
        setDeal(deal);

        // セット判定のために、手札のソートを行う
        sort(deal, deal + DEAL_CARD_NUM);

        // 手札が役付きかを判定し、
        // 役付きであれば 1, そうでなければ 0 を出力する
        int result =
            rule->isPod(DEAL_CARD_NUM, deal)? RESULT_TRUE : RESULT_FALSE;

        // 結果表示
        printf("%d\n", result);
    }

    // ルールの後片付け
    delete rule;

    return 0;
}

