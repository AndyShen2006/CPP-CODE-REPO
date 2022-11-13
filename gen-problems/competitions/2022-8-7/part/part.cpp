#include <bits/stdc++.h>

using namespace std;

constexpr int NOCOLOR = 0;
constexpr int RED = 1;
constexpr int BLUE = 2;
vector<int> G[100010];
int color[100010];
set<int> red;
set<int> blue;

void dfs(int x, int curcolor)
{
    if (curcolor == RED) {
        red.emplace(x);
        color[x] = RED;
    } else if (curcolor == BLUE) {
        blue.emplace(x);
        color[x] = BLUE;
    }
    for (auto it : G[x]) {
        if (!color[it]) {
            if (curcolor == RED) {
                dfs(it, BLUE);
            } else if (curcolor == BLUE) {
                dfs(it, RED);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, RED);
    if (red.size() > blue.size()) {
        for (auto it : red) {
            cout << it << ' ';
        }
        cout << endl;
        for (auto it : blue) {
            cout << it << ' ';
        }
        cout << endl;
    } else {
        for (auto it : blue) {
            cout << it << ' ';
        }
        cout << endl;
        for (auto it : red) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}