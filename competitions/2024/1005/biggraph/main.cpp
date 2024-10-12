#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    // freopen("data/biggraph1.in", "r", stdin);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;
        ll ans = 1;
        while (x < y / 3000) {
            ans *= ll(pow(ll(sqrt(3000)), 8. / 7.));
            y /= 3000;
        }
        cout << ans + ll(pow(ll(sqrt(y / x)), 8. / 7.)) << endl;
    }
    return 0;
}