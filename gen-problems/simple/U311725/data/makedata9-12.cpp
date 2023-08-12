#include <bits/stdc++.h>
#include <cdgall.hpp>

using namespace std;
using namespace cdg;

int main()
{
    int n = randint(10000, 1000000);
    int m = randint(1000000, 10000000);
    int pqMax = 1000000000 / m;
    int p = randint(pqMax / 2, pqMax);
    cout << n << ' ' << m << ' ' << p << ' ' << p << endl;
    return 0;
}