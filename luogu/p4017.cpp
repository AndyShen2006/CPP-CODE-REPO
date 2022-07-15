#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5010;

int inDeg[N];
int outDeg[N]; // It is used for checking which one is my answer
int len[N];
vector<int> nG[N];
queue<int> Q;
int cnt[N];

int main()
{
    // freopen("data/p4017.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int from, to;
    for (int i = 1; i <= m; i++) {
        cin >> from >> to;
        nG[from].push_back(to);
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
        node = Q.front();
        Q.pop();
        for (auto it : nG[node]) {
            // Add count
            cnt[it] = (cnt[it] + cnt[node]) % 80112002;
            len[it]++;
            // "Delete" this edge
            inDeg[it]--;
            if (inDeg[it] == 0) {
                Q.push(it);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (outDeg[i] == 0 && len[i] != 0) {
            ans = (ans + cnt[i]) % 80112002;
        }
    }
    cout << ans % 80112002 << endl;
    return 0;
}