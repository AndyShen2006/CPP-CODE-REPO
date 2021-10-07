#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];

int main()
{
    //freopen("data/Brandom1.in", "r", stdin);
    //freopen("data/Brandom1.out", "w", stdout);
    int n, X;
    scanf("%d %d", &n, &X);
    // a^b=X->a^X=b
    // b[i]->a[i]^X
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        b[i] = a[i] ^ X;
    }
    int ans = 0;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        ans += upper_bound(a + 1, a + n + 1, b[i]) - lower_bound(a + 1, a + n + 1, b[i]);
    }
    printf("%d\n", ans);
    return 0;
}