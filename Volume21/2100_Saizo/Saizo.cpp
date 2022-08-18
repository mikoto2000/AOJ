#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    // get dataset count.
    int datasetCount;
    cin >> datasetCount;

    for (int i = 0; i < datasetCount; i++) {
        // get data count.
        int dataCount;
        cin >> dataCount;

        // contain heights.
        int heights[dataCount];

        // get heights.
        for (int j = 0; j < dataCount; j++) {
            cin >> heights[j];
        }

        // calc gap.
        int maxUpGap = 0;
        int maxDownGap = 0;
        for (int j = 1; j < dataCount; j++) {
            int gap =  heights[j] - heights[j-1];
            if (gap > 0) {
                maxUpGap = max(maxUpGap, gap);
            } else {
                maxDownGap = max(maxDownGap, -gap);
            }
        }

        // print result.
        cout << maxUpGap << " " << maxDownGap << endl;

    }

    return 0;
}
