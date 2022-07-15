#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int u[110];
bool status[110];
vector<P> G[110];

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> status[i] >> u[i];
    }
    int from, to, w;
    for (int i = 1; i <= p; i++) {
        cin >> from >> to >> w;
        G[from].push_back(P(to, w));
    }
    return 0;
}