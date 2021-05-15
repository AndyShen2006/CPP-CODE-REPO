#include <bits/stdc++.h>

using namespace std;

bool chk1(int n)
{
    return n % 2 == 0;
}

bool chk2(int n)
{
    return n > 4 && n <= 12;
}

int main()
{
    int n;
    cin >> n;
    printf("%d %d %d %d", chk1(n) & chk2(n), chk1(n) | chk2(n), chk1(n) ^ chk2(n), !(chk1(n) || chk2(n)));
    return 0;
}