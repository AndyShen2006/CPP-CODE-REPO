#include <bits/stdc++.h>

using namespace std;

int s[300010];
vector<int> a;
vector<int> b;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int cnta = 1, cntb = 1;
    a.emplace_back(s[1]);
    b.emplace_back(s[1]);
    for (int i = 2; i <= n; i++) {
        if (s[i] >= a.back()) {
            a.emplace_back(s[i]);
            cnta++;
        } else {
            auto l = upper_bound(a.begin(), a.end(), s[i]);
            *l = s[i];
        }
        if (s[i] <= b.back()) {
            b.emplace_back(s[i]);
            cntb++;
        } else {
            auto l = lower_bound(b.begin(), b.end(), s[i], [](int a, int b) -> bool { return a >= b; });
            *l = s[i];
        }
    }
    cout << cnta << endl
         << cntb << endl;
    return 0;
}