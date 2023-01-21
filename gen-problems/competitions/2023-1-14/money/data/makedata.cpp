#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(1, 10000);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(1, 1000000) << ' ';
    }
    cout << endl;
    return 0;
}