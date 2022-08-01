#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 10010;
int val[MAX_N], nVal[MAX_N];
int dfn[MAX_N], low[MAX_N], dfc;
vector<int> G[MAX_N];
vector<int> nG[MAX_N];
stack<int> st;
bool ins[MAX_N];
int scc[MAX_N];
int inDeg[MAX_N], outDeg[MAX_N];
int dp[MAX_N];
queue<int> Q;

void tarjan(int x)
{
    dfn[x] = low[x] = ++dfc;
    st.push(x);
    ins[x] = true;
    for (auto it : G[x]) {
        if (!dfn[it]) {
            tarjan(it);
            low[x] = min(low[x], low[it]);
        } else if (ins[it]) {
            low[x] = min(low[x], dfn[it]);
        }
    }
    if (dfn[x] == low[x]) {
        int tmp;
        while (true) {
            tmp = st.top();
            if (!scc[tmp]) {
                scc[tmp] = x;
                ins[tmp] = false;
                st.pop();
                if (tmp == x) {
                    break;
                }
            } else {
                break;
            }
        }
    }
}

int main()
{
    freopen("data/p3387c.in", "r", stdin);
    //   Input
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
    }
    // Tarjan's Algorithm
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    // Generate a new graph
    for (int i = 1; i <= n; i++) {
        for (auto it : G[i]) {
            if (scc[it] != scc[i]) {
                nG[scc[i]].push_back(scc[it]);
                inDeg[scc[it]]++;
                outDeg[scc[i]]++;
            }
        }
        nVal[scc[i]] += val[i];
    }
    // Topo sort
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0 && scc[i] == i) {
            dp[i] = nVal[i];
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto it : nG[u]) {
            dp[it] = max(dp[it], dp[u] + nVal[it]);
            Q.push(it);
        }
    }
    // Output
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (outDeg[i] == 0 && scc[i] == i) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
