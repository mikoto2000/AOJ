/**
 * See: [ハッシュ探索②（オープンアドレス法） | Programming Place Plus　アルゴリズムとデータ構造編【探索アルゴリズム】　第７章](https://programming-place.net/ppp/contents/algorithm/search/007.html#double_hasing)
 */
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 最大操作数
#define MAX_OPERATION_COUNT 1000000

// 2 次ハッシュ関数を固定値 2 としているため、
// ハッシュテーブルの要素数は素数の必要がある。
// 最大入力個数(最大操作数)より大きい最小の素数でテーブルを作る
#define HASH_TABLE_SIZE 1000003

// `\0` 含めて最大 13 文字
#define MAX_STR_LENGTH 13

// 辞書
char d[HASH_TABLE_SIZE][MAX_STR_LENGTH];

// 'A', 'C', 'G', 'T' の 4 文字にそれぞれに数値を割り当て
inline short to_number(char c) {
    switch (c) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    }
}

// str 文字列を 5 進数として扱い、10 進数の値を返却
inline long long to_decimal(const char str[]) {
    unsigned short length = (short)strlen(str);

    // 10 進数
    long long decimal = 0;

    // 5 進数桁数
    long long p = 1;

    for (int i = 0; i < length; i++) {
        // 現在の 5 進数の桁を考慮して、 10 進数変換して decimal へ加算
        decimal += p * to_number(str[i]);

        // 桁を増やす
        p *= 5;
    }

    return decimal;
}

// 文字列を 10 進数表記にしたものを、ハッシュテーブル内の空間に収めるためにハッシュ化
unsigned int myhash(long long decimal) {
    return decimal % HASH_TABLE_SIZE;
}

// 衝突した際のリハッシュ
// See: [ハッシュ探索②（オープンアドレス法） | Programming Place Plus　アルゴリズムとデータ構造編【探索アルゴリズム】　第７章](https://programming-place.net/ppp/contents/algorithm/search/007.html#double_hasing)
unsigned int remyhash(long long hash) {
    return (hash + 2) % HASH_TABLE_SIZE;
}

void insert(char d[HASH_TABLE_SIZE][MAX_STR_LENGTH], const char str[]) {
    long long key = to_decimal(str);

    unsigned int hash = myhash(key);

    //cout << "insert start: " << str << endl;

    if(d[hash][0] == 0) {
        // 登録されたものが無い
        //cout << "insert str: " << str << ", hash: " << hash << endl;
        strcpy(d[hash], str);
    } else if (strcmp(str, d[hash]) == 0) {
        // 登録されていて、それが検索文字列と同じだった
        // do nothing
    } else {
        // 登録されていて、それが検索文字列と違ったので、リハッシュ処理に移る

        //cout << "start while str: " << str << ", hash: " << hash << endl;
        while ((hash = remyhash(hash))) {
            //cout << "str: " << str << ", hash: " << hash << ", exist: " << d[hash] << endl;
            if (hash >= HASH_TABLE_SIZE) {
                // リハッシュ先がテーブルの範囲外だった
                break;
            } else if (strcmp(str, (char*)d[hash]) == 0) {
                // リハッシュ先に登録されたものが、検索文字列と一致している
                // do nothing
                break;
            } else if(d[hash][0] == 0) {
                // リハッシュ先に登録されたものが無かった
                //cout << "insert str: " << str << ", hash: " << hash << endl;
                strcpy(d[hash], str);
                break;
            }
        }
    }
}

bool find(char d[HASH_TABLE_SIZE][MAX_STR_LENGTH], const char str[]) {
    long long key = to_decimal(str);

    //cout << "find start: " << str << endl;

    unsigned int hash = myhash(key);
    //cout << "str: " << str << ", hash: " << hash << endl;

    if (d[hash][0] == 0) {
        // 登録されているものが無い
        return false;
    } else if (strcmp(str, (char*)d[hash]) == 0) {
        // 登録されていて、それが検索文字列と同じだった
        return true;
    } else {
        // 登録されていて、それが検索文字列と違ったので、リハッシュ処理に移る

        while ((hash = remyhash(hash))) {
            //cout << "str: " << str << ", hash: " << hash << endl;
            if (d[hash][0] == 0) {
                // リハッシュ先に登録されたものが無かった
                return false;
            } else if (hash >= HASH_TABLE_SIZE) {
                // リハッシュ先がテーブルの範囲外だった
                return false;
            } else if (strcmp(str, (char*)d[hash]) == 0) {
                // リハッシュ先に登録されたものが、検索文字列と一致している
                return true;
            }
        }

        // ここには来ないはず
        return false;
    }
}

int main(int argc, char* argv[]) {

    // 命令数を取得
    unsigned int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        // 命令取得
        string operation;
        char str[MAX_STR_LENGTH];
        cin >> operation >> str;

        if (operation == "insert") {
            insert(d, str);
        } else if (operation == "find") {
            if (find(d, str)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}

