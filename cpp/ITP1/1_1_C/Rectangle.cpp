#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{

    int a,b;

    cin >> a >> b;
    
    int area = a * b;
    int circuit = a * 2 + b * 2;

    cout << area << " " << circuit << endl;

    return 0;
}
