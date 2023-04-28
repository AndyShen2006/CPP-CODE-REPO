#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

typedef long long ll;

int main()
{
    ll a = randint(100, 200);
    ll b = a * randint(10, 12);
    ll g = __gcd(a, b);
    ll c = g * randint(10, 20) + 1;
    ll y = randint(10, 100);
    ll x = y + c;
    ll m = randint(10, 100);
    ll n = a + m;
    fprintf(stderr, "%lld %lld %lld %lld\n", a, b, c, g);
    cout << x << ' ' << y << ' ' << m << ' ' << n << ' ' << b << endl;
    return 0;
}