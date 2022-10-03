#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    vector<long> vec;

    // クエリの数 q を取得
    unsigned int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        // 命令を取得
        unsigned short operation;
        cin >> operation;

        switch (operation) {
            case 0:
                // pushBack
                long item;
                cin >> item;

                vec.push_back(item);

                break;
            case 1:
                // randomAccess
                long index;
                cin >> index;
                cout << vec[index] << endl;
                break;
            case 2:
                // popBack
                vec.pop_back();
                break;
        }
    }

    return 0;
}

