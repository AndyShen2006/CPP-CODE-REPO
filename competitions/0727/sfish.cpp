#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll tripow(int p)
{
    int ans = 1;
    for (int i = 1; i <= p; i++) {
        ans *= 3;
    }
    return ans;
}

ll compute(int k)
{
    ll ans = 0;
    int cnt = 0;
    while (k > 0) {
        ans += (k & 1) * tripow(cnt);
        k >>= 1;
        cnt++;
    }
    return ans;
}

int main()
{
    freopen("sfish.in", "r", stdin);
    freopen("sfish.out", "w", stdout);
    int n;
    cin >> n;
    int k;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        cout << compute(k) << endl;
    }
    return 0;
}