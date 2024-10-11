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

    unsigned char operation;
    while (cin >> operation) {
        switch (operation) {
            case 'N':
                n(dice);
                break;
            case 'S':
                s(dice);
                break;
            case 'E':
                e(dice);
                break;
            case 'W':
                w(dice);
                break;
        }
    }

    // 表面の数字を出力
    cout << dice[0] << endl;

    return 0;
}

