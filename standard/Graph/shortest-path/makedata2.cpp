#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("spfa2.in", "w", stdout);
    int n = 99999, m = 199996;
    printf("%d %d\n", n, m);
    for (int i = n; i >= 2; --i)
        printf("1 %d %d\n%d %d 1\n", i, (n - i + 1) * 2 + 1, i, i - 1);
}