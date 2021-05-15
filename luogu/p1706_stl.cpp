#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int a[9];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    do {
        for (int i = 1; i <= n; i++) {
            printf("%5d", a[i]);
        }
        printf("\n");
    } while (next_permutation(a + 1, a + n + 1));
    return 0;
}