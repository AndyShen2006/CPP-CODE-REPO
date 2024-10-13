#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 2e5 + 10;
pair<int, int> ops[MAX_N];
string a, b;

void apply(int l, int r)
{
    for (int i = l; i <= r; i++) {
        swap(a[i - 1], b[i - 1]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 1; i <= m; i++) {
        cin >> ops[i].first >> ops[i].second;
    }
    sort(ops + 1, ops + n + 1);
    for (int i = 1; i <= m; i++) {
        if (b[i - 1]) {
        }
    }
    return 0;
}