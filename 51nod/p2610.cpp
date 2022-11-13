#include <bits/stdc++.h>

using namespace std;

const int INF = 100000;

//PreInitalization

map<int, set<int>> G;
int nodes[INF];
int par[INF];
bool haveson[INF] = { 0 };
int total = 0;

void dfs(int n)
{
    int minb = INF;
    if (nodes[n] == -1 && !haveson[n] || nodes[n] != -1) {
        return;
    }
    for (int it : G[n]) {
        minb = min(minb, nodes[it]);
    }
    nodes[n] = minb;
    total += nodes[n] - nodes[par[n]];
    for (int it : G[n]) {
        dfs(it);
    }
    return;
}

int main()
{
    //Initalization & Input
    int n, temp;
    cin >> n;
    par[1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        G[i + 1].insert(temp);
        G[temp].insert(i + 1);
        haveson[temp] = true;
        par[i + 1] = temp;
    }
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        nodes[i] = temp;
    }
    dfs(1);
    cout << total << endl;
    return 0;
}