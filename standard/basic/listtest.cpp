#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000;
constexpr int M = 1000000;

int head[N], to[M], weight[M], nxt[M];

void init(int n, int m)
{
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        nxt[i] = -1;
    }
}

inline void link(int u, int v, int w, int num)
{
    nxt[num] = head[u];
    head[u] = num;
    to[num] = v;
    weight[num] = w;
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(n, m);
    int from, to, w;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> w;
        link(from, to, w, i);
    }
    return 0;
}