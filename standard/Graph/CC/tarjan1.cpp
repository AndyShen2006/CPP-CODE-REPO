#include <bits/stdc++.h>
using namespace std;

const int N = 20;

vector<int> g[N], T[N * 2];
int dfn[N], low[N], cut[N];
int dfc = 0, cnt; // �Ѿ������˼�����
int root;
int stk[N], top;

int n, m;

void dfs(int x, int parent, bool getCutEdge = false)
{
    dfn[x] = low[x] = ++dfc; // ���ʵ� x������� dfnֵ �ͳ�ʼ lowֵ
    stk[++top] = x;
    printf("init dfn[%d] = low[%d] = %d\n", x, x, dfn[x]);
    int cntChild = 0; // x �� rootʱ��¼��������
    for (auto y : g[x]) {
        if (y == parent)
            continue;

        2 if (!dfn[y])
        { // dfn[y] == 0, y δ�����ʹ�
            printf("find child of %d: %d\n", x, y);
            if (x == root)
                cntChild++;
            printf("child %d not visited, recursive dfs(%d)\n", y, y);
            dfs(y, x, getCutEdge); // �ݹ���ʺ���y
            if (low[y] < low[x])
                printf("change low[%d] from %d to %d\n", x, low[x], low[y]);
            low[x] = min(low[x], low[y]); // ���ӵ�lowֵ���Դ���������
            if (low[y] == dfn[x]) {
                ++cnt;
                printf("  Found a New BCC #%d.\n", cnt - N);
                for (int i = 0; i != y; --top) {
                    i = stk[top];
                    T[cnt].push_back(i);
                    T[i].push_back(cnt);
                    printf("   BCC #%d has vertex #%d\n", cnt - N, i);
                }
                T[cnt].push_back(x);
                T[x].push_back(cnt);
                printf("   BCC #%d has vertex #%d\n", cnt - N, x);
            }
            if (getCutEdge) {
                if (low[y] > dfn[x])
                    printf("%d -- %d is a cut edge\n", x, y);
            } else {
                if (x == root && cntChild > 0)
                    printf("cntChild = %d\n", cntChild);
                if ((x == root && cntChild >= 2) || (x != root && low[y] >= dfn[x])) { // ���ָ�㣺����������޻ر�
                    cut[x] = 1;
                    cout << x << " is a cut point\n";
                }
            }
        }
        else
        { // y ֮ǰ�Ѿ����ʹ�,���ǡ��رߡ�
            if (dfn[y] < low[x])
                printf("back edge %d -> %d, change low[%d] to dfn[%d]=%d\n", x, y, x, y, dfn[y]);
            low[x] = min(low[x], dfn[y]); // ���ܡ��̳С����ӵ� dfn��
        }
    }
}

int main()
{
    // freopen("data/bf1.in", "r", stdin);
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (auto j : g[i])
            cout << j << "\t";
        cout << endl;
    }
    cout << endl
         << endl;
    root = 1;
    cnt = N;
    // dfs(root, root, true);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i, i, false); // ����ͼ����ͨʱ��Ҫ����
    cout << endl
         << endl;
    for (int i = 1; i <= n; i++) {
        printf("low[%d] = %d, cut[%d] = %d\n", i, low[i], i, cut[i]);
    }
    return 0;
}

/*
10 12
1 2
1 4
2 3
2 5
3 5
3 6
3 8
4 8
6 9
8 9
8 10
10 7

graph G {
    rankdir=TB
# 10 12
    1 -- 2 [style="" color="red"]
    1 -- 4 [style="dashed" color="blue"]
    2 -- 3 [style="" color="red"]
    2 -- 5 [style="dashed" color="red"]
    3 -- 5 [style="" color="red"]
    3 -- 6 [style="" color="green"]
    3 -- 8 [style="dashed" color="green"]
    4 -- 8 [style="" color="blue"]
    6 -- 9 [style="" color="green"]
    8 -- 9 [style="" color="green"]
    8 -- 10 [style="" color="orange"]
    10 -- 7 [style="" color="orange"]

    1 [label="1" shape="" color="" style=""]
    10 [label="10" shape="" color="" style=""]
    2 [label="2" shape="" color="" style=""]
    3 [label="3" shape="" color="" style=""]
    4 [label="4" shape="" color="" style=""]
    5 [label="5" shape="" color="" style=""]
    6 [label="6" shape="" color="" style=""]
    7 [label="7" shape="" color="" style=""]
    8 [label="8" shape="" color="" style=""]
    9 [label="9" shape="" color="" style=""]
}

������ϰ���P3388
*/
