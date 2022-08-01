#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("data/A1.in", "r", stdin);
    int s, t;
    cin >> s >> t;
    int n, m;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        cout << n * m - ((n + 1) >> 1) * ((m + 1) >> 1) << ' ' << 0.5 << endl;
    }
    return 0;
}