#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000000;

int inDeg[N] = { 0 };
int outDeg[N] = { 0 }; // It is used for checking which one is my answer
vector<int> G[N];
queue<int> Q;
int cnt[N] = { 0 };

int main()
{
    // freopen("data/example.in", "r", stdin);
    // freopen("data/example.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int from, to;
    for (int i = 1; i <= m; i++) {
        cin >> from >> to;
        G[from].push_back(to);
        inDeg[to]++;
        outDeg[from]++;
    }
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) {
            Q.push(i);
            cnt[i] = 1;
        }
    }
    int node;
    while (!Q.empty()) {
        node = Q.front(), Q.pop();
        for (auto it : G[node]) {
            // Add count
            cnt[it] += cnt[node];
            // "Delete" this edge
            inDeg[it]--;
            if (inDeg[it] == 0) {
                Q.push(it);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // if (outDeg[i] == 0) {
        //     printf("%d %d\n", i, cnt[i]);
        // }
        ans += outDeg[i] == 0 ? cnt[i] : 0;
    }

    cout << ans << endl;
    return 0;
}