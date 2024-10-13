#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p1 = 100000000000000003, p2 = p1 + 2;

int main()
{
    ll mod;
    cin >> mod;
    cout << p1 % mod << ' ' << p2 % mod;
    return 0;
}