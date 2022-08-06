#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5e5 + 5;
vector<int> G[MAX_N];

int dfn[MAX_N], low[MAX_N], dfc;
int root, ans;
stack<int> st;
vector<int> bcc[MAX_N];
int scccnt;

void tarjan(int x, int par)
{
    int cntTree = 0;
    dfn[x] = low[x] = ++dfc;
    st.emplace(x);
    for (auto it : G[x]) {
        if (it == par) {
            continue;
        }
        if (!dfn[it]) {
            cntTree++;
            tarjan(it, x);
            low[x] = min(low[it], low[x]);
            if (low[it] >= dfn[x]) {
                int tmp;
                scccnt++;
                while (true) {
                    tmp = st.top();
                    st.pop();
                    bcc[scccnt].emplace_back(tmp);
                    if (tmp == it) {
                        break;
                    }
                }
                bcc[scccnt].emplace_back(x);
            }
        } else {
            low[x] = min(dfn[it], low[x]);
        }
    }
    if (par == -1 && cntTree == 0) {
        bcc[++scccnt].emplace_back(x);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for (int i = 1; i <= n; i++) {
        root = i;
        if (!dfn[i]) {
            tarjan(root, -1);
        }
    }
    cout << scccnt << endl;
    for (int i = 1; i <= scccnt; i++) {
        cout << bcc[i].size() << ' ';
        for (auto it : bcc[i]) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}