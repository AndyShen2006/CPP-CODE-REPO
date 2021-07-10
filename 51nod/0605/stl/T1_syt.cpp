#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, x;
ll a[100001];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &x);
        printf("%c\n", binary_search(a + 1, a + n + 1, x) ? 'Y' : 'N');
    }
    return 0;
}
