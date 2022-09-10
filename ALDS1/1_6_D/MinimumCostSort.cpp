/**
 * See: https://blog.ikappio.com/solve-minimum-cost-sort-using-cpp/
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    // 荷物の数 N を取得
    unsigned short n;
    cin >> n;

    // 荷物の情報を取得
    unsigned short a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // ソート済み配列を作成
    unsigned short b[n];
    memcpy(b, a, sizeof(unsigned short) * n);
    sort(b, b + n);

    // 抽出済み要素をマークする配列
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // グループ化実施
    vector<vector<unsigned int>*> groups;
    unsigned int next_a_index = 0;
    while (next_a_index < n) {
        vector<unsigned int> *vec = new vector<unsigned int>();
        groups.push_back(vec);

        // グループを作るために、繋がっている要素をたぐる
        unsigned int start_a_index = next_a_index;
        for(;;) {
            // グループを表す vector に追加
            vector<unsigned int> *current_vec = groups.back();
            current_vec->push_back(a[next_a_index]);

            // 抽出済みとしてマーク
            visited[next_a_index] = true;

            // 次の要素をたぐる
            unsigned int target_weight = a[next_a_index];
            unsigned short *next_weight_of_b = find(b, b + n, target_weight);
            unsigned int next_weight_index_of_b = std::distance(b, next_weight_of_b);
            next_a_index = next_weight_index_of_b;

            // cout << "target_weight: " << target_weight << endl;
            // cout << "next_weight_of_b: " << *next_weight_of_b << endl;
            // cout << "next_weight_index_of_b: " << next_weight_index_of_b << endl;
            // cout << "next_a_index: " << next_a_index << endl;
            // cout << "start_a_index: " << start_a_index << endl;

            // for (int x = 0; x < n; x++) {
            //     cout << visited[x] << " ";
            // }
            // cout << endl;

            // 手繰り始めたときの要素がまた登場したらそのグループの抽出は完了
            if (next_a_index == start_a_index) {
                break;
            }
        }

        // 抽出済みでない要素を探す
        auto next_a = find(visited, visited + n, false);
        if (next_a == visited + n) {
            // 抽出済みの要素が無ければグループ化終了
            break;
        }
        next_a_index = distance(visited, next_a);
        // cout << "outer next_a_index: " << next_a_index << endl;
    }

    // グループのコスト計算
    unsigned int total_cost = 0;
    unsigned int all_min = *(min_element(a, a + n));
    for (auto g : groups) {
        auto num = g->size();
        auto sum = accumulate(g->begin(), g->end(), 0);

        // for (auto x : *g) {
        //     cout << x << " ";
        // }
        // cout << endl;

        auto current_min = *(min_element(g->begin(), g->end()));
        // cout << "current_min: " << current_min << endl;

        // グループ内の最小で計算したコスト
        unsigned int cost1 = sum + (num - 2) * current_min;
        // cout << "cost1: " << cost1 << endl;

        // 配列内の最小で計算したコスト
        unsigned int cost2 = sum + current_min + (num + 1) * all_min;
        // cout << "cost2: " << cost2 << endl;

        total_cost += min(cost1, cost2);
    }

    cout << total_cost << endl;

    return 0;
}

