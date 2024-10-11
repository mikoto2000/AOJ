#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int calc_flood_area(vector<pair<unsigned char, int>> map, vector<pair<unsigned char, int>>::iterator start, vector<pair<unsigned char, int>>::iterator end) {
    double area = 0;
    int current_depth = 0;

    for(auto it = start; it != end; ++it) {
        switch (it->first) {
            case '\\':
                area += current_depth;
                area += 0.5;
                current_depth++;
                break;
            case '/':
                area += 0.5;
                current_depth--;
                area += current_depth;
                break;
            default:
                area += current_depth;
                break;
                ; // do nothing
        }
    }

    return area;
}

int main(int argc, char* argv[]) {
    int current_height = 0;

    // 地形情報取得用変数
    vector<pair<unsigned char, int>> map;

    // 地形情報取得
    unsigned char c;
    while(cin >> c) {
        map.push_back(make_pair(c, current_height));

        switch (c) {
            case '\\':
                current_height--;
                break;
            case '/':
                current_height++;
                break;
            default:
                ; // do nothing
        }
    }

    // 最後の高さを記録。地形はダミーの平地で。
    map.push_back(make_pair('_', current_height));


    // 水たまり計算
    vector<int> areas;
    auto find_start_iterator = map.begin();
    auto start_flood = find_if(find_start_iterator, map.end(), [](auto const value) { return value.first == '\\'; });

    while (start_flood != map.end()) {
        // 水たまり開始位置と同じ高さのものがあるか判定
        auto end_flood = find_if(next(start_flood), map.end(), [&](auto const value) { return value.second == start_flood->second; });

        // 同じ高さのものが無ければ、次の '\\' を探して水たまり計算を再開
        if (end_flood == map.end()) {
            start_flood = find_if(next(start_flood), map.end(), [](auto const value) { return value.first == '\\'; });
            continue;
        }

        // 水たまりが存在したら面積を計算して vector へ push_back
        areas.push_back((int)calc_flood_area(map, start_flood, end_flood));

        // 水たまりの終わりから、次の '\\' を探して水たまり計算を再開
        start_flood = find_if(end_flood, map.end(), [](auto const value) { return value.first == '\\'; });
    }


    // 水たまりの総面積を出力
    auto sum = accumulate(areas.begin(), areas.end(), 0);
    cout << sum << endl;

    // 各水たまりの情報を出力
    if (areas.size() > 0) {
        cout << areas.size() << " ";
        for (auto it = areas.begin(); it != --(areas.end()); it++) {
            cout << *it << " ";
        }
        cout << *(--(areas.end())) << endl;
    } else {
        cout << areas.size() << endl;
    }

    return 0;
}

