#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll prefix[1000010];

int main()
{
    int n, q;
    cin >> n >> q;
    ll tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        prefix[i] = prefix[i - 1] + tmp;
    }
    int f, t;
    for (int i = 1; i <= q; i++) {
        cin >> f >> t;
        cout << prefix[t] - prefix[f - 1] << endl;
    }
    return 0;
}