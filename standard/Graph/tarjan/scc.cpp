#include <bits/stdc++.h>

using namespace std;

map<int, set<int>> G;
const int maxV = 1000;
bool isFind[maxV] = { false };

void dfs(int start)
{
    cout << start;
    for (auto it : G[start]) {
        if (!isFind[it]) {
            dfs(it);
        }
    }
}

int main()
{
    freopen("scc.in", "r", stdin);
    int n, m; //n->vertex,m->edge
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int tempA, tempB;
    for (int i = 0; i < m; i++) {
        cin >> tempA >> tempB;
        G[tempA].insert(tempB);
        G[tempB].insert(tempA);
    }
    dfs(3);
    return 0;
}