#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("data/gcd02.in", "r", stdin);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    long long T, l, r, x;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> l >> r >> x;
        cout << (r / x == l / x ? l / x : 1) << endl;
    }
    return 0;
}