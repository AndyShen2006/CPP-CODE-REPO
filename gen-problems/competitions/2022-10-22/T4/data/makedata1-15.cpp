#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n, m, q;
    n = randint(50, 500);
    m = randint(n * 2, 1000);
    q = randint(1, 100);
    printf("%d %d %d\n", n, m, q);
    int type;
    for (int i = 1; i <= m; i++) {
        type = randint(1, 11);
        if (type >= 1 && type <= 5) {
            cout << randint(1, n) << " -> " << randint(1, n) << endl;
        } else if (type >= 6 && type <= 10) {
            cout << randint(1, n) << " <- " << randint(1, n) << endl;
        } else if (type == 11) {
            cout << randint(1, n) << " <-> " << randint(1, n) << endl;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << randint(1, n) << ' ' << randint(1, n) << endl;
    }
    return 0;
}