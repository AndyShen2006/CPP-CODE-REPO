#include <bits/stdc++.h>

using namespace std;

// Has been accepted on test 1
// Notice: Should test pt 2
constexpr int MAX_N = 1000010;
typedef long long ll;
ll val[MAX_N], pre[MAX_N];
ll la[MAX_N], ra[MAX_N];
priority_queue<ll, vector<ll>, greater<ll>> ps;

int main()
{
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
    int n;
    cin >> n;
    ll tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        val[i] += tmp;
    }
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        val[i] -= tmp;
    }
    // Left
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + val[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << pre[i] << ' ';
    // }
    // cout << endl;
    ps.push(0);
    for (int i = 1; i <= n; i++) {
        la[i] = pre[i] - ps.top();
        ps.push(pre[i]);
    }
    // Process Side effect & Preparing for next process.
    memset(pre, 0, sizeof(pre));
    while (!ps.empty()) {
        ps.pop();
    }
    reverse(val + 1, val + n + 1);
    // Right
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + val[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << pre[i] << ' ';
    // }
    // cout << endl;
    ps.push(0);
    for (int i = 1; i <= n; i++) {
        ra[i] = pre[i] - ps.top();
        ps.push(pre[i]);
    }
    // Compute answer
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << la[i] << ' ' << ra[n - i + 1] << endl;
        ans ^= (max(la[i], ra[n - i + 1]) + 1000000000);
    }
    cout << ans << endl;
    return 0;
}