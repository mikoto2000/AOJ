#include <iostream>

using namespace std;

void call(int n) {

    for (int i = 1; i <= n; i++) {
        int x = i;
        if ( x % 3 == 0 ){
            cout << " " << i;
            continue;
        }

        do {
            if ( x % 10 == 3 ){
                cout << " " << i;
                break;
            }
            x /= 10;
        } while (x);
    }

    // 標準出力
    cout << endl;
}

int main(int argc, char* argv[]) {

    // 標準入力を取得
    short n;
    cin >> n;

    call(n);

    return 0;
}

