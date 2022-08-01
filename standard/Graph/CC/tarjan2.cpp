#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> g[N], T[N * 2];
int n, m;

int dfn[N], scc[N], low[N];
int cntDfn, cntScc, dfc;
int stk[N], top;
bool instk[N];

void dfs(int x)
{
    dfn[x] = low[x] = ++cntDfn; // init
    instk[stk[top++] = x] = true; // push x to stack and set flag
    printf("init dfn[%d]=%d, low[%d]=%d, push %d into stack\n", x, dfn[x], x,
        low[x], x);
    for (auto y : g[x]) {
        if (!dfn[y]) { // not visited
            printf("%d (child of %d) not visited, recursive to dfs(%d)\n", y, x, y);
            dfs(y);
            if (low[y] < low[x])
                printf("change low[%d] from %d to %d (low[%d]) (child-parent edge: %d "
                       "<- %d)\n",
                    x, low[x], low[y], y, y, x);
            low[x] = min(low[x], low[y]);
        } else { // already visited
            // low[x] = min(low[x], dfn[y]);
            printf("%d is already visited, instk[%d] = %s\n", y, y,
                instk[y] ? "true" : "false");
            if (instk[y]) { // back edge to a stack node
                printf("back edge to a stack node: %d <- %d\n", y, x);
                if (dfn[y] < low[x])
                    printf("change low[%d] from %d to %d (dfn[%d], back edge)\n", x,
                        low[x], dfn[y], y);
                low[x] = min(low[x], dfn[y]);
            }
        }
    }
    if (low[x] == dfn[x]) { // a new SCC found
        scc[x] = ++cntScc;
        printf("a new SCC found (SCC[%d]), === pop stack ===:", cntScc);
        while (true) {
            int z = stk[--top]; // get top of stack
            instk[z] = false; // reset the flag
            scc[z] = cntScc; //  join to Scc
            printf("\t%d", z);
            if (z == x) { // top of stack is x
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    freopen("dataTarjanScc.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v); // direct graph
    }
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (auto j : g[i])
            printf("%d\t", j);
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i); // must traverse all not visited one
    return 0;
}

/*
reference: https://www.cnblogs.com/ycx-akioi/p/Tarjan-algorithm-solve-SCC.html
8  13
1  2
2  3
3  1
4  5
4  8
5  6
6  1
6  7
7  1
7  3
7  5
8  4
8  6

digraph G {
    rankdir=TB
# 8  13
    1 -> 2 [style="" color="red"]
    2 -> 3 [style="" color="red"]
    3 -> 1 [style="dashed" color="red"]
    4 -> 5 [style="" color="green"]
    4 -> 8 [style="" color="blue"]
    5 -> 6 [style="" color="green"]
    6 -> 1 [style="dashed" color=""]
    6 -> 7 [style="" color="green"]
    7 -> 1 [style="dashed" color=""]
    7 -> 3 [style="dashed" color=""]
    7 -> 5 [style="dashed" color="green"]
    8 -> 4 [style="dashed" color="blue"]
    8 -> 6 [style="dashed" color=""]

    1 [label="1" shape="" color="" style=""]
    2 [label="2" shape="" color="" style=""]
    3 [label="3" shape="" color="" style=""]
    4 [label="4" shape="" color="" style=""]
    5 [label="5" shape="" color="" style=""]
    6 [label="6" shape="" color="" style=""]
    7 [label="7" shape="" color="" style=""]
    8 [label="8" shape="" color="" style=""]
}

 */
