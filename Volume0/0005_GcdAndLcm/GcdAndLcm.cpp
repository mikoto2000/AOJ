#include <iostream>
#include <string>

#define ULLI unsigned long long int

using namespace std;

ULLI gcd(ULLI a, ULLI b )
{
  ULLI c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

ULLI lcm(ULLI m, ULLI n) {
        return m / gcd(m, n) * n;
}

int main(int argc, char* argv[]) {
    ULLI i, j;

    while (cin >> i >> j) {
        cout << gcd(i,j) << " " << lcm(i, j) << endl;
    }

    return 0;
}
