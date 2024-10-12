#include <bits/stdc++.h>

using namespace std;
/*
One example:
8 2 1 5 3 4 7 6
---------------
1 2 3 4 5 6 7 8
n y n n n n y n
6 2 1 5 3 4 7 8
4 2 1 5 3 6 7 8
5 2 1 4 3 6 7 8
3 2 1 4 5 6 7 8
1 2 3 4 5 6 7 8
6 points 5 steps;

Another example:
6 10 3 2 8 9 7 5 1 4
--------------------
9 10 3 2 8 6 7 5 1 4
1 10 3 2 8 6 7 5 9 4


In this case, we can assume an algorithm as follows:
1. Add edges from p_i to i
2. Calculate String Connection Components(Use Tarjan's Algorithm)
3. sum(cnt(scc_i)-1) is the answer.
Fin.
*/

constexpr int MAX_N = 5e5 + 10;
vector<int> G[MAX_N];
set<int> scc[MAX_N];
int sccno[MAX_N], scccnt;
int dfn[MAX_N], low[MAX_N], cnt;
stack<int> st;
bool ins[MAX_N];

void tarjan(int x)
{
    dfn[x] = low[x] = ++cnt;
    st.push(x);
    ins[x] = true;
    for (auto it : G[x]) {
        if (!dfn[it]) {
            tarjan(it);
            low[x] = min(low[x], low[it]);
        } else if (ins[it]) {
            low[x] = min(low[x], dfn[it]);
        }
    }
    if (low[x] == dfn[x]) {
        int tmp;
        scccnt++;
        while (true) {
            tmp = st.top();
            st.pop();
            ins[tmp] = false;
            scc[scccnt].insert(tmp);
            sccno[tmp] = scccnt;
            if (tmp == x) {
                break;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int tmpP;
    for (int i = 1; i <= n; i++) {
        cin >> tmpP;
        G[tmpP].push_back(i);
    }
    // Tarjan's Algorithm
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= scccnt; i++) {
        ans += scc[i].size() - 1;
    }
    cout << ans << endl;
    return 0;
}