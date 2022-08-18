#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    
    int n, x;
    while (cin >> n >> x) {

        // if n == 0, x == 0 end of data.
        if (n == 0 && x == 0) {
            break;
        }

        // count pattern of (x == (i + j + k).
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (x == (i + j + k)) {
                        count++;
                    }
                }
            }
        }

        // print result.
        cout << count << endl;

    }
    return 0;
}
