#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 10000;
constexpr int CONFLICT = 10;

inline int Hash(int x, int p1, int p2)
{
    return (x * p1) % p2;
}

int hmap[MAX_N][CONFLICT];
int pos[MAX_N]; // 添加元素时判断当前位置

int main()
{
    int n, q;
    cin >> n >> q;
    memset(hmap, 0xff, sizeof(hmap));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int h = Hash(x, 7, 13);
        hmap[h][pos[h]++] = x;
    }
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int h = Hash(x, 7, 13);
        for (int i = 0; i < pos[h]; i++) {
            if (hmap[h][i] == x) {
                cout << "YES" << endl;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}