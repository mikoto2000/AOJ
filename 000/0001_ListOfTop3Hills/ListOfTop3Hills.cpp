#include <iostream>
#include <algorithm>

using namespace std;

#define MOUNTAIN_NUM 10
#define TOP_X 3

int main(int argc, char** argv) {
    int mountains[10];

    for (int i = 0; i < MOUNTAIN_NUM; i++) {
        cin >> mountains[i];
    }

    sort(mountains, mountains + MOUNTAIN_NUM, greater<int>());

    for (int i = 0; i < TOP_X; i++) {
        cout << mountains[i] << endl;
    }
}
