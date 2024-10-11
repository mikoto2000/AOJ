#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {

    int n;
    while (cin >> n) {
        // if "n = 0", end of data.
        if (n == 0) {
            break;
        }

        // initialized sum.(beforehand except n)
        int sum = -n;
        int size = sqrt(n);
        for (int i = 1; i <= size; i++) {
            if (n % i == 0) {
                // add divisor.
                sum += i;

                // calc another divisor.
                int j = n/i;

                // if not overlap divisor,
                // add another divisor.
                if (i != j) {
                    sum += j;
                }
            }
        }

        // print result.
        string result;
        if (n < sum) {
            result = "abundant number";
        } else if (n == sum) {
            result = "perfect number";
        } else {
            result = "deficient number";
        }

        cout << result << endl;
    }

    return 0;
}

