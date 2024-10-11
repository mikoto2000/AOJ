#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {

    // プロセス数とクオンタムを取得
    unsigned int n;
    unsigned short q;
    cin >> n >> q;

    queue<pair<string, unsigned int>> process_queue;

    for (unsigned int i = 0; i < n; i++) {
        // プロセス名と処理時間を取得
        string name;
        unsigned int time;
        cin >> name >> time;
        process_queue.push(make_pair(name, time));
    }

    // プロセスの処理実行
    int all_time = 0;
    while (!process_queue.empty()) {
        // キューから取り出し
        pair<string, int> process = process_queue.front();
        process_queue.pop();

        // 処理実行
        int process_time = process.second - (int)q;

        // 終了判定
        if (process_time <= 0) {
            // 終了した

            // 全体の処理時間更新
            all_time += q + process_time;

            // 終了時間を出力
            cout << process.first << " " << all_time << endl;
        } else {
            // 終了してない

            // 全体の処理時間更新
            all_time += q;

            // キューに戻す
            process_queue.push(make_pair(process.first, process_time));
        }

    }

    return 0;
}

