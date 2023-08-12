#include <bits/stdc++.h>

using namespace std;

int a[1310], b[1310];
vector<string> cache;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memcpy(b, a, sizeof(a));
    sort(b + 1, b + 1301, greater<int>());
    cache.reserve(1000010);
    int idx = 1;
    while (idx <= n) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                continue;
            }
            if (a[i] == b[idx]) {
                cache.emplace_back("A C");
                idx++;
                a[i] = -1;
            } else {
                cache.emplace_back("A B");
            }
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] == -1) {
                continue;
            }
            if (a[i] == b[idx]) {
                cache.emplace_back("B C");
                idx++;
                a[i] = -1;
            } else {
                cache.emplace_back("B A");
            }
        }
    }
    cout << cache.size() << endl;
    for (const auto& it : cache) {
        cout << it << endl;
    }
    return 0;
}