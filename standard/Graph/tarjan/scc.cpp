#include <bits/stdc++.h>

using namespace std;

map<int, set<int>> T;
const int maxV = 1000;
bool isFind[maxV] = { false };

void dfs(int start)
{
    cout << start;
    for (auto it : T[start]) {
        if (!isFind[it]) {
            dfs(it);
        }
    }
}

int main()
{
    freopen("scc.in", "r", stdin);
    int n, m; // n->vertex,m->edge
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int tempA, tempB;
    for (int i = 0; i < m; i++) {
        cin >> tempA >> tempB;
        T[tempA].insert(tempB);
        T[tempB].insert(tempA);
    }
    dfs(3);
    return 0;
}