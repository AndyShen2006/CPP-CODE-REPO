#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define DEBUG 0

constexpr int MAX_N = 100010;
// "Leftest Right"
int lr[MAX_N], a[MAX_N];
// "Leftest Right Zero"
ll lrz[MAX_N];

void init()
{
    memset(lr, 0, sizeof(lr));
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        ll n, v, mul = 1;
        init();
        deque<pair<int, ll>> dq; // pos,data
        cin >> n >> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (v == 0) {
            cout << (n * (n + 1) >> 1) << endl;
            continue;
        }
        // Last Zero Position
        ll lzp = n + 1;
        for (ll i = n; i >= 1; i--) {
            if (a[i] == 0) {
                lrz[i] = i;
                lzp = i;
            } else {
                lrz[i] = lzp;
            }
        }
#if DEBUG
        for (int i = 1; i <= n; i++) {
            cerr << lrz[i] << ' ';
        }
        cerr << endl;
#endif
        for (int i = 1; i <= n; i++) {
            if (!a[i]) {
                mul = 1;
                dq.clear();
                continue;
            }
            mul *= a[i];
            dq.emplace_back(i, a[i]);
            while (mul >= v && !dq.empty()) {
                lr[dq.front().first] = i;
                // cerr << dq.front().first << ' ' << i  << ' ' << mul << endl;
                mul /= dq.front().second;
                dq.pop_front();
            }
        }

#if DEBUG
        for (int i = 1; i <= n; i++) {
            cerr << lr[i] << ' ';
        }
        cerr << endl;
#endif
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (lr[i]) {
                ans += lrz[i] - lr[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
