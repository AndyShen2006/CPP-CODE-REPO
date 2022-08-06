#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[100001];
deque<pair<ll, int>> Q;
ll Min[100001];
ll f[100001];
ll sum[100001];

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!Q.empty() && i - Q.front().second >= c) {
            Q.pop_front();
        }
        while (!Q.empty() && a[i] < Q.back().first) {
            Q.pop_back();
        }
        Q.emplace_back(make_pair(a[i], i));
        Min[i] = Q.front().first;
    }
    for (int i = 1; i < c; i++) {
        f[i] = f[i - 1] + a[i];
    }
    for (int i = c; i <= n; i++) {
        f[i] = min(f[i - 1] + a[i], f[i - c] + sum[i] - sum[i - c] - Min[i]);
    }
    cout << f[n] << endl;
    return 0;
}