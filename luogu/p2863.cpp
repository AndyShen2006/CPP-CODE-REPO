#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e4 + 10;
vector<int> G[MAX_N];
set<int> scc[MAX_N];
int sccno[MAX_N], scccnt;
int dfn[MAX_N], low[MAX_N], cnt;
stack<int> st;
bool ins[MAX_N];

map<int, set<int>> nG;
int deg[MAX_N], outDeg[MAX_N];

void tarjan(int x)
{
    dfn[x] = low[x] = ++cnt;
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
    if (low[x] == dfn[x]) {
        int tmp;
        scccnt++;
        while (true) {
            tmp = st.top();
            if (!sccno[tmp]) {
                st.pop();
                ins[tmp] = false;
                scc[scccnt].insert(tmp);
                sccno[tmp] = scccnt;
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
    // freopen("data/p3387b.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
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
            if (sccno[i] != sccno[it] && nG[sccno[i]].find(sccno[it]) == nG[sccno[i]].end()) {
                deg[sccno[it]]++;
                outDeg[sccno[i]]++;
                nG[sccno[i]].insert(sccno[it]);
            }
        }
    }
    // Compute array val && Add nodes
    int ans = 0;
    for (int i = 1; i <= scccnt; i++) {
        if (scc[i].size() > 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}