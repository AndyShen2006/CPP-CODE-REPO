#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 10000;

inline int Hash(int x, int p1, int p2)
{
    return (x * p1) % p2;
}

int hmap[MAX_N];

int main()
{
    int n, q;
    cin >> n >> q;
    memset(hmap, 0xff, sizeof(hmap));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        hmap[Hash(x, 7, 13)] = x;
    }
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (hmap[Hash(x, 7, 13)] != -1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}