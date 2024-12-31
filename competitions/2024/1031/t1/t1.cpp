#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0
constexpr int MAX_N = 3e5 + 10;
typedef long long ll;
set<ll> sig;
pair<ll, ll> ps[MAX_N];
priority_queue<ll, vector<ll>, greater<ll>> pq;
int t[MAX_N];
bool ans[MAX_N];

int main()
{
    // freopen("t1.in", "r", stdin);
    // freopen("t1.ans", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= k; i++) {
        pq.push(t[i]);
        ps[i] = make_pair(0, t[i]);
    }
    for (int i = k + 1; i <= n; i++) {
        ll x = pq.top();
        pq.pop();
        ps[i] = make_pair(x, x + t[i]);
        pq.push(x + t[i]);
    }
    cout << pq.top() << endl;
    sig.insert(pq.top());
    // Back Trace
    for (int i = n; i >= 1; i--) {
        if (sig.find(ps[i].second) != sig.end()) {
            sig.insert(ps[i].first);
            if (i <= k) {
                ans[i] = true;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
