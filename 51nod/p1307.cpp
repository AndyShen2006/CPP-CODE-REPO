#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 50010;
const ll INF = 0x3f3f3f3f;
//node is in [0,MAX_N-1]
ll av[MAX_N];

int main()
{
    freopen("data/p1307a.in", "r", stdin);
    //Initalization
    int n, pi;
    ll ci, wi;
    av[0] = INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ci >> wi >> pi;
        pi++; //Turn -1 to 0
        av[i] = min(av[pi] - wi, ci - wi);
        printf("%d %lld\n", i, av[i]);
        if (av[i] < 0) {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}