#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    int n = randint(10, 20);
    int m = randint(100000, 200000);
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(1, 2000) << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(1, 1000000) << ' ';
    }
    cout << endl;
    return 0;
}
