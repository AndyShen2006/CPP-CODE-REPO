#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int l = randint(1, 100000), r = randint(1, 100000);
    cout << max(l, r) << ' ' << min(l, r) << endl;
    return 0;
}