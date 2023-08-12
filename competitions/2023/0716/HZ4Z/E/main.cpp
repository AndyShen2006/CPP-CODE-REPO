#include <bits/stdc++.h>

using namespace std;

vector<int> G[110];
int width[110], depth[110];
bool vis[110];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    width[1] = 1;
    vis[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto it : G[x]) {
            if (vis[it]) {
                continue;
            }
            depth[it] = depth[x] + 1;
            width[depth[it]]++;
            q.push(it);
            vis[it] = true;
        }
    }
    cout << *max_element(depth + 1, depth + n + 1) << endl
         << *max_element(width + 1, width + n + 1) << endl;
    return 0;
}