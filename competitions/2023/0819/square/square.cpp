#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n;
    cin >> n;
    cout << 4 * n * ceil(1.0 * n / 4) - (4 + 4 + (ceil(1.0 * n / 4) - 1) * 16) * ceil(1.0 * n / 4) / 2 << ' ' << 4 * n * int(n / 4) - (12 + 12 + int(n / 4 - 1) * 16) * (n / 4) / 2 << endl;
    return 0;
}