#include <iostream>

using namespace std;

const unsigned int BUILDING_COUNT = 4;
const unsigned int FLOOR_COUNT = 3;
const unsigned int ROOM_OF_FLOOR = 10;

void printBuilding(unsigned int tenants_count[FLOOR_COUNT][ROOM_OF_FLOOR]) {
    for (int floor = 0; floor < FLOOR_COUNT; floor++) {
        for (int room = 0; room < ROOM_OF_FLOOR; room++) {
            cout << " " << tenants_count[floor][room];
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    // 標準入力を取得
    unsigned int n;
    cin >> n;

    // 公舎の入居者情報初期化
    // tenants_count[building][floor][room]
    unsigned int tenants_count[BUILDING_COUNT][FLOOR_COUNT][ROOM_OF_FLOOR]{};

    // 入居・退去の情報を読み込んで公舎の入居差情報を更新
    for (int i = 0; i < n; i++) {
        int b, f, r, v;
        cin >> b >> f >> r >> v;

        // ゼロベースインデックスに変換
        b--;
        f--;
        r--;

        tenants_count[b][f][r] += v;
    }

    // 結果出力
    printBuilding(tenants_count[0]);
    cout << "####################" << endl;
    printBuilding(tenants_count[1]);
    cout << "####################" << endl;
    printBuilding(tenants_count[2]);
    cout << "####################" << endl;
    printBuilding(tenants_count[3]);

    return 0;
}

