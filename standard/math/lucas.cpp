#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
long long C(ll n, ll m, ll p)
{
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        i =
    }
}

long long Lucas(long long n, long long m, long long p)
{
    if (m == 0)
        return 1;
    return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}

int main()
{

    return 0;
}