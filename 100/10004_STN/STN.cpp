#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{

    int s, m, l, tmp;

    cin >> s >> m >> l;

    if (s > m) {
        tmp = s;
        s = m;
        m = tmp;
    }

    if (s > l ) {
        tmp = s;
        s = l;
        l = tmp;
    }

    if (m > l ) {
        tmp = m;
        m = l;
        l = tmp;
    }

    cout << s << " " << m << " " << l << endl;
    
    return 0;
}
