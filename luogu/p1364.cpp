#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

vector<int> G[110];
bool isFound[110];
queue<P> Q;
int value[110];

int main()
{
    int n;
    int w, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w >> u >> v;
        value[i] = w;
        if (u != 0) {
            G[i].push_back(u);
            G[u].push_back(i);
        }
        if (v != 0) {
            G[i].push_back(v);
            G[v].push_back(i);
        }
    }
    int ans = INT_MAX, temp;
    for (int i = 1; i <= n; i++) {
        memset(isFound, 0, sizeof(isFound));
        temp = 0;
        Q.push(P(i, 0));
        isFound[i] = true;
        while (!Q.empty()) {
            P top = Q.front();
            Q.pop();
            temp += value[top.first] * top.second;
            // printf("%d %d\n", value[top.first], top.second);
            for (auto it : G[top.first]) {
                if (!isFound[it]) {
                    isFound[it] = true;
                    Q.push(P(it, top.second + 1));
                }
            }
        }
        // cout << temp << endl;
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}