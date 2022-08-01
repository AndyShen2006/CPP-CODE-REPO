#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int u[110];
int c[110];
int indeg[110];
int outdeg[110];
vector<P> G[110];
queue<int> Q;

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
    }
    int from, to, w;
    for (int i = 1; i <= p; i++) {
        cin >> from >> to >> w;
        G[from].push_back(P(to, w));
        outdeg[from]++;
        indeg[to]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!indeg[i] && c[i]) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        if (c[a] > 0) {
            for (auto it : G[a]) {
                c[it.first] += it.second * c[a];
            }
        }
    }
    return 0;
}