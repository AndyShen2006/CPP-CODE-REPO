#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

typedef long long ll;

int main()
{
    ll x = randint(100000000, 1000000000);
    ll y = randint(10000000, 99999999);
    ll m = randint(100000000, 1000000000);
    ll n = randint(10000000, 99999999);
    ll l = randint(800000000, 2000000000);
    printf("%lld %lld %lld %lld %lld\n", x, y, m, n, l);
    return 0;
}