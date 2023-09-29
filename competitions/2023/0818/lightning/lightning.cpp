#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int ma = 0, ta;
    for (int i = 1; i <= n; i++) {
        cin >> ta;
        ma = max(ma, ta);
    }
    cout << ceil(1.0 * ma / x) << endl;
    return 0;
}