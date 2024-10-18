#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1010;
int n, m;

double pc[MAX_N];
double p(int x)
{
    if (x <= 0) {
        return 1;
    }
    if (pc[x] != 0) { // 记忆化搜索
        return pc[x];
    }
    double ans = 0;
    for (int i = 1; i <= m - 1; i++) {
        ans += p(x - i);
    }
    ans /= m;
    pc[x] = ans;
    return ans;
}

double fc[MAX_N];
double f(int x)
{
    if (x <= 0) {
        return 1;
    }
    if (fc[x] != 0) {
        return fc[x];
    }
    double ans = 0;
    for (int i = 1; i <= m - 1; i++) {
        ans += f(x - i) * p(x - i);
    }
    ans /= m;
    fc[x] = ans;
    return ans;
}

int main()
{
    cin >> n >> m;
    cout << fixed << setprecision(5) << f(n) << endl;
    return 0;
}
