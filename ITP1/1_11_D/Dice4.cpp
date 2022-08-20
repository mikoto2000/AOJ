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

bool is_equals(short* dice, short* dice2) {
    // 一致判定
    for (short i = 0; i < 6; i++) {
        if (dice[i] != dice2[i]) {
            // 不一致
            return false;
        }
    }

    // 一致
    return true;
}

bool is_dice_equals(short* dice, short* dice2) {
    bool is_equals_flag = false;

    // 全パターン転がして比較
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);

    s(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);

    e(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);

    s(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);

    s(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);

    e(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);

    s(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);
    cw(dice);
    is_equals_flag |= is_equals(dice, dice2);

    return is_equals_flag;
}

int main(int argc, char* argv[]) {

    // サイコロの数取得
    short dice_count;
    cin >> dice_count;

    // サイコロの領域確保
    short dices[dice_count][6];

    // サイコロの情報取得
    for (short i = 0; i < dice_count; i++) {
        for (short j = 0; j < 6; j++) {
            cin >> dices[i][j];
        }
    }

    // サイコロ比較
    bool is_found_same = false;
    for (short i = 0; i < dice_count; i++) {
        for (short j = i; j < dice_count; j++) {
            if (i == j) {
                continue;
            }

            if (is_dice_equals(dices[i], dices[j])) {
                // 同じものが見つかった
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // 全部違う
    cout << "Yes" << endl;
    return 0;
}

