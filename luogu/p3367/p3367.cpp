#include <stdio.h>

#define MAX_N 200010

int par[MAX_N];
int depth[MAX_N];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        depth[i] = 1;
    }
}

int find(int n)
{
    if (par[n] == n)
        return n;
    else {
        return find(par[n]);
    }
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (depth[a] > depth[b]) {
        par[b] = a;
    } else {
        par[a] = b;
        if (a == b)
            depth[b]++;
    }
}

int isSamePar(int a, int b)
{
    return find(a) == find(b);
}

int main()
{
    //freopen("p1551.in", "r", stdin);
    int n, m;
    scanf("%d%d",&n,&m);
    init(n + 10);
    int zi, xi, yi;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d",&zi,&xi,&yi);
        if(zi==1)  unite(xi, yi);
        else{
            if(isSamePar(xi,yi))  printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}