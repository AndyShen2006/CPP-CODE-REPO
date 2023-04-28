#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 66000;
vector<int> G[MAX_N];
vector<int> T[MAX_N];
int indeg[MAX_N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        while (true) {
            cin >> tmp;
            if (tmp == 0) {
                break;
            }
            G[tmp].push_back(i);
            indeg[i]++;
        }
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) {
            que.push(i);
        }
    }
    while (!que.empty()) {
    }
    return 0;
}