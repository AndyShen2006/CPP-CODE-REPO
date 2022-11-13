#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, m = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a < m) {
            cnt++;
        }
        m = max(a, m);
    }
    cout << cnt << endl;
    return 0;
}