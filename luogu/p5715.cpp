#include <bits/stdc++.h>

using namespace std;

int a[3];

int main()
{
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    printf("%d %d %d", a[0], a[1], a[2]);
    return 0;
}
