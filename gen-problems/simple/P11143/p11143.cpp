#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 2e5 + 10;
pair<ll, ll> ps[MAX_N];

int main()
{
    ll n, m;
    int k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> ps[i].first >> ps[i].second;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        if (ps[i].second >= ps[i].first) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}