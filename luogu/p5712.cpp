#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    printf("Today, I ate %d apple", x);
    if (x <= 1)
        cout << ".";
    else
        cout << "s.";
    return 0;
}