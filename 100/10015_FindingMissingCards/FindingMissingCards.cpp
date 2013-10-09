#include <algorithm>
#include <iostream>
#include <vector>

#define SUIT_NUM 4
#define RANK_NUM 13

using namespace std;

char itoc(int suitInt) {
    char suit;
    switch (suitInt) {
        case 0:
            suit = 'S';
            break;
        case 1:
            suit = 'H';
            break;
        case 2:
            suit = 'C';
            break;
        case 3:
            suit = 'D';
            break;
    }
    return suit;
}

int ctoi(char suit) {
    int suitInt;
    switch (suit) {
        case 'S':
            suitInt = 0;
            break;
        case 'H':
            suitInt = 1;
            break;
        case 'C':
            suitInt = 2;
            break;
        case 'D':
            suitInt = 3;
            break;
    }
    return suitInt;
}

int main(int argc, char const* argv[])
{
    // init card status.
    bool cards[SUIT_NUM][RANK_NUM];
    fill((bool*)cards, (bool*)(cards + SUIT_NUM), false);

    // get card num.
    int n;
    cin >> n;

    // check existing cards.
    for (int i = 0; i < n; i++) {
        // get card.
        char suit;
        unsigned short rank;
        cin >> suit >> rank;

        // rank number fix to index number.
        rank--;

        // convert suit char to int.
        int suitInt = ctoi(suit);

        // change card status to true.
        cards[suitInt][rank] = true;
    }

    // print result.
    for (int i = 0; i < SUIT_NUM; i++) {
        for (int j = 0; j < RANK_NUM; j++) {
            if (!cards[i][j]) {
                cout << itoc(i) << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}

