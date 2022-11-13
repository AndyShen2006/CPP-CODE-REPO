#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5e4 + 10;
vector<int> G[MAX_N];
set<int> scc[MAX_N];
int sccno[MAX_N], scccnt;
int dfn[MAX_N], low[MAX_N], cnt;
stack<int> st;
bool ins[MAX_N];

int nG[510][510];

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
            st.pop();
            ins[tmp] = false;
            scc[scccnt].insert(tmp);
            sccno[tmp] = scccnt;
            if (tmp == x) {
                break;
            }
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    int a, b;
    string type;
    for (int i = 1; i <= m; i++) {
        cin >> a >> type >> b;
        if (type == "->") {
            G[a].push_back(b);
        } else if (type == "<-") {
            G[b].push_back(a);
        } else if (type == "<->") {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    // Tarjan's Algorithm
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    // cout << scccnt << endl;
    // Generate a new graph
    for (int i = 1; i <= n; i++) {
        for (auto it : G[i]) {
            nG[sccno[i]][sccno[it]] = 1;
        }
    }
    // Floyd Algorithm
    for (int i = 1; i <= scccnt; i++) {
        for (int j = 1; j <= scccnt; j++) {
            for (int k = 1; k <= scccnt; k++) {
                nG[i][j] |= nG[i][k] & nG[k][j];
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> a >> b;
        if (sccno[a] == sccno[b]) {
            cout << a << " <-> " << b << endl;
        } else if (nG[sccno[a]][sccno[b]]) {
            cout << a << " -> " << b << endl;
        } else if (nG[sccno[b]][sccno[a]]) {
            cout << a << " <- " << b << endl;
        } else {
            cout << "Fail" << endl;
        }
    }
    return 0;
}