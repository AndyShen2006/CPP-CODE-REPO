#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int f[1000001];
deque<pair<int, int>> Q; // Value,Position

int main()
{
    freopen("data/4a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++) {
        f[i] = a[i];
        Q.push_back(make_pair(f[i], i));
        while (!Q.empty() && f[i] < Q.back().first) {
            Q.pop_back();
        }
    }
    for (int i = m + 1; i <= n; i++) {
        if (!Q.empty() && i - Q.front().second > m) {
            Q.pop_front();
        }
        f[i] = Q.front().first + a[i];
        while (!Q.empty() && f[i] < Q.back().first) {
            Q.pop_back();
        }
    }
    cout << f[n] << endl;
    return 0;
}