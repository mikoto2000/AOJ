#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SwapLine {
    public:
        int height;
        int line1;
        int line2;
        void set(int height, int line1, int line2);
};

void SwapLine::set(int height, int line1, int line2) {
    this->height = height;
    this->line1 = line1;
    this->line2 = line2;
}

// for sort of SwapLine.
bool DescSwapLine(const SwapLine& line1, const SwapLine& line2) {
    return line1.height > line2.height;
}

class Amida {
    private:
        int horizontalLineCount;
        SwapLine *swapLines;

    public:
        Amida(int horizontalLineCount, SwapLine *swapLines);
        int execute(int targetLine);
};

Amida::Amida(int horizontalLineCount, SwapLine *swapLines) {
    this->horizontalLineCount = horizontalLineCount;
    this->swapLines = swapLines;
}

int Amida::execute(const int targetLine) {
    int currentLine = targetLine;
    int currentHeight = 1000;

    for (int i = 0; i < horizontalLineCount; i++) {
        SwapLine currentTarget = swapLines[i]; 

        if (currentHeight < currentTarget.height) {
            // do nothing.
        } else if (currentTarget.line1 == currentLine) {
            currentLine = currentTarget.line2;
            currentHeight = currentTarget.height - 1;
        } else if (currentTarget.line2 == currentLine)  {
            currentLine = currentTarget.line1;
            currentHeight = currentTarget.height - 1;
        }
    }

    return currentLine;
}

int main(int argc, char const* argv[])
{
    while (true) {
        // read problem info.
        int verticalLineCount, swapLineCount, targetLineNum;
        cin >> verticalLineCount >> swapLineCount >> targetLineNum;

        // if "0 0 0" is data end.
        if (verticalLineCount == 0
                && swapLineCount == 0
                && targetLineNum == 0) {
            break;
        }

        // read swap lines.
        SwapLine swapLines[swapLineCount];
        for (int i = 0; i < swapLineCount; i++) {
            int height, line1, line2;
            // line1 < line2.
            cin >> height >> line1 >> line2;
            swapLines[i].set(height, line1, line2);
        }

        // sort order by desc.
        sort(swapLines, swapLines + swapLineCount, DescSwapLine);

        // create Amida.
        Amida *amida = new Amida(swapLineCount, swapLines);

        // print result.
        cout << amida->execute(targetLineNum) << endl;

        // clean Amida.
        delete amida;
    }

    return 0;
}

