#include <iostream>

using namespace std;

/**
 * 北側に転がした時の処理
 *
 * 0(表) → 4(N)
 * 4(N) → 5(裏)
 * 5(裏) → 1(S)
 * 1(S) → 0(表)
 */
void n(short s[6]) {
    short tmp = s[0];
    s[0] = s[1];
    s[1] = s[5];
    s[5] = s[4];
    s[4] = tmp;
}

/**
 * 南側に転がした時の処理
 *
 * 0(表) → 1(S)
 * 1(S) → 5(裏)
 * 5(裏) → 4(N)
 * 4(N) → 0(表)
 */
void s(short s[6]) {
    short tmp = s[0];
    s[0] = s[4];
    s[4] = s[5];
    s[5] = s[1];
    s[1] = tmp;
}

/**
 * 東側に転がした時の処理
 *
 * 0(表) → 2(E)
 * 2(E) → 5(裏)
 * 5(裏) → 3(W)
 * 3(W) → 0(表)
 */
void e(short s[6]) {
    short tmp = s[0];
    s[0] = s[3];
    s[3] = s[5];
    s[5] = s[2];
    s[2] = tmp;
}

/**
 * 西側に転がした時の処理
 *
 * 0(表) → 3(W)
 * 3(W) → 5(裏)
 * 5(裏) → 2(E)
 * 2(E) → 0(表)
 */
void w(short s[6]) {
    short tmp = s[0];
    s[0] = s[2];
    s[2] = s[5];
    s[5] = s[3];
    s[3] = tmp;
}

/**
 * 上から見て右回転
 *
 * 4(N) → 2(E)
 * 2(E) → 1(S)
 * 1(S) → 3(W)
 * 3(W) → 4(N)
 */
void cw(short s[6]) {
    short tmp = s[4];
    s[4] = s[3];
    s[3] = s[1];
    s[1] = s[2];
    s[2] = tmp;
}

/**
 * 上から見て左回転
 *
 * 4(N) → 3(W)
 * 3(W) → 1(S)
 * 1(S) → 2(E)
 * 2(E) → 4(N)
 */
void ccw(short s[6]) {
    short tmp = s[4];
    s[4] = s[2];
    s[2] = s[1];
    s[1] = s[3];
    s[3] = tmp;
}

int main(int argc, char* argv[]) {

    // サイコロの数値を取得
    // 0: 表側の数字
    // 1: S 側の数字
    // 2: E 側の数字
    // 3: W 側の数字
    // 4: N 側の数字
    // 5: 裏側の数字
    short dice[6];
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    // 質問の数を取得
    short number;
    cin >> number;

    for (short i = 0; i < number; i++) {
        // 上面と前面の値取得
        short up, south;
        cin >> up >> south;

        // 上面判定
        short up_dice_index = 0;
        for (int j = 0; j < 6; j++) {
            if (dice[j] == up) {
                up_dice_index = j;
                break;
            }
        }

        // サイコロの上面を質問にそろえる
        switch (up_dice_index) {
            case 0:
                // do nothing
                break;
            case 1:
                n(dice);
                break;
            case 2:
                w(dice);
                break;
            case 3:
                e(dice);
                break;
            case 4:
                s(dice);
                break;
            case 5:
                n(dice);
                n(dice);
                break;
        }

        // 手前判定
        short south_dice_index = 0;
        for (int j = 0; j < 6; j++) {
            if (dice[j] == south) {
                south_dice_index = j;
                break;
            }
        }

        // サイコロの手前を質問にそろえる
        switch (south_dice_index) {
            case 0:
                // ありえない
                break;
            case 1:
                // do nothing
                break;
            case 2: // E
                cw(dice);
                break;
            case 3: // W
                ccw(dice);
                break;
            case 4: // N
                cw(dice);
                cw(dice);
                break;
            case 5:
                // ありえない
                break;
        }

        // 回答を出力
        cout << dice[2] << endl;

    }

    return 0;
}
