#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5001;
vector<int> G[MAX_N];
int dfn[MAX_N], low[MAX_N], dfc;
stack<int> st;
map<int, set<int>> scc;
bool instack[MAX_N];

void tarjan(int x)
{
    dfn[x] = low[x] = ++dfc;
    st.emplace(x);
    instack[x] = true;
    for (auto it : G[x]) {
        if (!dfn[it]) {
            tarjan(it);
            low[x] = min(low[x], low[it]);
        } else if (instack[it]) {
            low[x] = min(low[x], dfn[it]);
        }
    }
    if (low[x] == dfn[x]) {
        int tmp;
        while (true) {
            tmp = st.top();
            st.pop();
            instack[tmp] = false;
            scc[x].insert(tmp);
            if (tmp == x) {
                break;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, t;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> t;
        G[a].emplace_back(b);
        if (t == 2) {
            G[b].emplace_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int cnt = 0, pos;
    for (const auto& it : scc) {
        if (it.second.size() > cnt) {
            cnt = it.second.size();
            pos = it.first;
        }
    }
    cout << cnt << endl;
    for (auto it : scc[pos]) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}