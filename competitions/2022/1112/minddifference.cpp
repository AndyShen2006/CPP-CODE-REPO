#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int s = m * n;
    int x, y;
    for (int i = sqrt(s); i >= 1; i--) {
        if (s % i == 0) {
            x = i;
            y = s / i;
            if (__gcd(x, y) == m) {
                cout << y - x << endl;
                exit(0);
            }
        }
    }
    return 0;
}