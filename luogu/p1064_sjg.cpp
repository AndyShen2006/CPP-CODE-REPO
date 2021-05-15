#include <algorithm>
#include <iostream>
using namespace std;

#define MAXM 65

int n; // 总钱数，相当于背包容量约束
int m; // 物品个数
struct Object {
    int id;
    int v; // 物品价格
    int product; // v*p 相当于物品价值
    int p; // 物品重要度
    int q; // 该物品对应的主件id （数组中下标） 0=无上级主件
} Q[MAXM]; // 物品数组  Q[0] not used
int sel[MAXM]; // 标记物品是否取 select[0] not used
bool cmp(Object a, Object b)
{
    if ((a.q == 0 && b.q == 0) || (a.q > 0 && b.q > 0))
        return a.p > b.p;
    else {
        return a.q == 0;
    }
    //if ((a.q == 0 && b.q > 0) || a.p > b.p)
    //    return true; // 主件在附件前面 或者 重要度高的排前面
    //    else
    //    return false;
}

int cmoney; // current used money
int cproduct; // current product
int bestproduct; // current best product

int Bound(int t) // t (1~m) is depth of backtrack, t-th object
{
    int cleft = n - cmoney; // money left
    int b = cproduct;
    while (t <= m && Q[t].v <= cleft) { // try to select as many as can
        cleft -= Q[t].v;
        b += Q[t].product;
        ++t;
    }
    if (t <= m)
        b += cleft * Q[t].p; // try to select part of Q[t]
    return b;
}

void backtrack(int t)
{
    if (t > m) {
        bestproduct = cproduct;
        // printf("best %d\n", bestproduct);
        return;
    } // reach a leaf
    if (cmoney + Q[t].v <= n && (Q[t].q == 0 || sel[Q[t].q])) { // left child
        cmoney += Q[t].v;
        cproduct += Q[t].product;
        sel[Q[t].id] = 1;
        // printf("sel[%d]=1\n", Q[t].id);
        backtrack(t + 1);
        cmoney -= Q[t].v;
        cproduct -= Q[t].product;
        sel[Q[t].id] = 0;
        // printf("sel[%d]=0\n", Q[t].id);
    }
    if (Bound(t + 1) > bestproduct) {
        sel[Q[t].id] = 0;
        // printf("sel[%d]=0\n", Q[t].id);
        backtrack(t + 1); // right child
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &Q[i].v, &Q[i].p, &Q[i].q);
        Q[i].product = Q[i].v * Q[i].p;
        Q[i].id = i;
    }
    sort(Q + 1, Q + m + 1, cmp);
    // for_each(Q+1, Q+m+1, [](Object o) -> void { printf("%d %d %d %d\n",o.id,o.v,o.p,o.q);});
    backtrack(1);
    printf("%d\n", bestproduct);
    return 0;
}
