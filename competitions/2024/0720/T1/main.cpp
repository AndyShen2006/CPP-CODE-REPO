#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int ans1 = 0, ans2 = 0, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ans1 = max(ans1, a);
        ans2 |= a;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}