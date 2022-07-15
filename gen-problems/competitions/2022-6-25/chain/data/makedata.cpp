#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    freopen("example2.in", "w", stdout);
    int V = randint(10, 20);
    int E = randint(20, 30);
    cout << V << ' ' << E << endl;
    for (int i = 1; i <= E; i++) {
        while (true) {
            int from = randint(1, V);
            int to = randint(1, V);
            if (from > to) {
                cout << from << ' ' << to << endl;
                break;
            }
        }
    }
    return 0;
}