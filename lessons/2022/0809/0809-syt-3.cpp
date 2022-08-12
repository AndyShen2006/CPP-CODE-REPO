#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;
int ans[1 << 10];
map<int, int> mapping;

inline int lowbit(int x)
{
    return ((x) & (-x));
}

struct BIT {
    int maxc[1 << 10];
    void add(int x, int y)
    {
        while (x <= n) {
            maxc[x] += y;
            x += lowbit(x);
        }
    }
    int max(int x)
    {
        int res = 0;
        while (x > 0) {
            res += maxc[x];
            x -= lowbit(x);
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    int val;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        a.push_back(val);
        mapping.insert(make_pair(val, 0)); //第二位先闲置不用
    }
    int cnt = 1;
    for (auto& it : mapping) {
        it.second = cnt; //处理出第二位，也就是离散化之后的值
        cnt++;
    }
    int real;
    BIT tree {};
    for (int i = 0; i < a.size(); i++) {
        real = mapping[a[i]];
        tree.add(real, i);
        ans[i] = i + 1 - tree.max(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}