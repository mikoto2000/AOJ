#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    while (true) {
        // Get card num.
        int n;
        cin >> n;

        // if n == 0 exit.
        if (n == 0) {
            return 0;
        }

        // Initialize score.
        int as = 0;
        int bs = 0;
        
        // Repeat card number.
        for (int i = 0; i < n; i++) {
            // Get cards.
            int ac, bc;
            cin >> ac >> bc;

            // Update score.
            if (ac == bc) {
                as += ac;
                bs += bc;
            } else if (ac > bc) {
                as += ac + bc;
            } else {
                bs += ac + bc;
            }
        }

        // Output score.
        cout << as << " " << bs << endl;
    }
}
