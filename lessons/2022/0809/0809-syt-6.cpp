#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> b[100000]; // val,pos
int mapping[100000]; //下标是位置，返回离散后的值
int ans;

inline int lowbit(int x)
{
    return ((x) & (-x));
}

struct BIT {
    int sumc[1 << 10];
    void add(int x, int y)
    {
        while (x <= n) {
            sumc[x] = ::max(sumc[x], y);
            x += lowbit(x);
        }
    }
    int max(int x)
    {
        int res = 0;
        while (x > 0) {
            res = ::max(sumc[x], res);
            x -= lowbit(x);
        }
        return res;
    }
};

int main()
{
    freopen("data/6.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    stable_sort(b + 1, b + n + 1); //由于可能存在多个相同数，所以考虑采用稳定排序
    for (int i = 1; i <= n; i++) {
        mapping[b[i].second] = i;
    }
    BIT tree {};
    int real, tmp;
    for (int i = 1; i <= n; i++) {
        real = mapping[i];
        tmp = tree.max(real - 1) + 1;
        tree.add(real, tmp);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}