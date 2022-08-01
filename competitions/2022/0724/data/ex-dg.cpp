#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    int n = randint(1, 1e6);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(1, 1e9) << ' ';
    }
    cout << endl;
    cout << randint(n, 2e9);
    return 0;
}