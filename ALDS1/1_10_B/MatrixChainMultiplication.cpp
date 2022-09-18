#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {

    // 行列の数 n を取得
    unsigned short n;
    cin >> n;

    // 行列の幅と高さを記録する配列
    // M[i] の行列の高さ(行数)は p[i], 幅(列数) は p[i + 1] になる
    // (M[0] の行列の高さ(行数)は p[0], 幅(列数) は p[0 + 1] になる)
    int p[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> p[i + 1];
    }

    // コスト計算用ツリーを格納する配列を作成
    // See: https://twitter.com/mikoto2000/status/1571546288122130432
    // Mi から Mj までをかけ合わせた時の最小コスト m[i][j] に格納する
    int m[n][n];
    memset(m, 0, sizeof(int) * n * n);

    // l は現在計算中の要素のツリー上での高さ
    for (int l = 1; l < n; l++) {

        // i は、「今回分割の組み合わせを考えるグループの先頭」
        // ツリー上の高さが高くなるにつれて、考えなきゃいけない組み合わせが増えていく
        // (高さ 0, 1 なら組み合わせは一通り、高さ 2 なら組み合わせは 2 通り、
        //  高さ 4 なら組み合わせは 4 通り、高さ 5 なら組み合わせは 5 通り)
        // See: https://twitter.com/mikoto2000/status/1571546288122130432
        for (int i = 0; i < n - l; i++) {

            // j は、「今回分割の組み合わせを考えるグループの末尾」
            int j = i + l;

            //cout << "l: " << l << endl;
            //cout << "i: " << i << endl;
            //cout << "j: " << j << endl;

            m[i][j] = INT_MAX;

            // k は『「今回分割の組み合わせを考えるグループ」を
            // 分割したときの「左グループの最後の要素」』
            // 先頭ひとつだけのパターンから始めて末尾ひとつだけのパターンまでを
            // for 文で回して、一番小さいコストのものを採用する。
            for (int k = i; k < j; k++) {
                //cout << "k: " << k << endl;
                //cout << "p: ";
                //for (int i = 0; i <= n; i++) {
                //    cout << " " << p[i];
                //}
                //cout << endl;
                //cout << "m[i][j],\tm[i][k] + m[k + 1][j]\t+ p[i]\t* p[k + 1]\t* p[j + 1])" << endl;
                //cout << "m[" << i << "][" << j << "],\tm[" << i << "][" << k << "] + m[" << k << " + 1][" << j << "]\t+ p[" << i << "]\t* p[" << k << " + 1]\t* p[" << j << " + 1])" << endl;
                //cout << "m[" << i << "][" << j << "],\tm[" << i << "][" << k << "] + m[" << k + 1 << "][" << j << "]\t+ p[" << i << "]\t* p[" << k + 1 << "]\t\t* p[" << j + 1 << "])" << endl;
                //cout << "" << m[i][j] << ",\t\t" << m[i][k] << "\t+ " << m[k + 1][j] << "\t\t+ " << p[i] << "\t* " << p[k + 1] << "\t\t* " << p[j + 1] << ")" << endl;

                // m[i][j]                    : 初期値または前回の k のパターンまでのコストの最小値
                // m[i][k] + m[k + 1][j]      : 一段深いところまでのコスト
                // p[i] * p[k + 1] * p[j + 1] : 今の深さのコスト(i から k と、 k + 1 から j のパターン)
                // p[i]                       : 「今回分割の組み合わせを考えるグループの先頭」の行数
                // p[k + 1]                   : 「今回分割の組み合わせを考えるグループの末尾」の列数(See: 15 行目)
                // → p[i] と p[k + 1] で、合体済みの行列の行と列を表す
                // p[j + 1]                   : 「今回分割の組み合わせを考えるグループの末尾」の列数(See: 15 行目)
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);

                //for (int i = 0; i < n; i++) {
                //    for (int j = 0; j < n; j++) {
                //        cout << "\t" << m[i][j];
                //    }
                //    cout << endl;
                //}
                //cout << endl;
            }
        }
    }

    //for (int i = 0; i < n; i++) {
    //    cout << " " << p[i];
    //}
    //cout << endl;

    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        cout << " " << m[i][j];
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    cout << m[0][n - 1] << endl;

    return 0;
}

