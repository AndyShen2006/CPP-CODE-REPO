#include <bits/stdc++.h>
using namespace std;

int n;
void perm(int a[], int k, int m)
{
    if (k == m) {
        for (int i = 1; i <= n; i++)
            printf("%5d", a[i]);
        printf("\n");
    } else {
        for (int i = k; i <= m; i++) {
            swap(a[i], a[k]);
            printf("swap %d and %d\n", a[i], a[k]);
            printf("begin do perm a[%d]...a[%d]\n", k + 1, m);
            perm(a, k + 1, m);
            swap(a[i], a[k]);
            printf("swap %d and %d\n", a[i], a[k]);
        }
    }
}

int a[15];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    perm(a, 1, n);
    return 0;
}
