#include <iostream>

using namespace std;

#define A 80
#define B 65
#define C 50
#define D 30

int main(int argc, char const* argv[])
{
    while(true) {
        int m, f, r;
        cin >> m >> f >> r;

        // "-1 -1 -1" is end of data.
        if (m == -1
                && f == -1
                && r == -1) {
            break;
        }

        // check grade.
        int score = m + f;
        char grade;
        if (m == -1 || f == -1) {
            grade = 'F';
        } else if (score >= A) {
            grade = 'A';
        } else if (score >= B) {
            grade = 'B';
        } else if (score >= C) {
            grade = 'C';
        } else if (score >= D) {
            // challenge retest.
            if (r >= C) {
                grade = 'C';
            } else {
                grade = 'D';
            }
        } else {
            grade = 'F';
        }

        // print grade.
        cout << grade << endl;
    }

    return 0;
}
