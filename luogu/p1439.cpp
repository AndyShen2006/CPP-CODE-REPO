#include <bits/stdc++.h>

using namespace std;

int a[100001], b[100001], mapping[100001];
vector<int> v;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mapping[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = b[mapping[i]];
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
    exit(0);
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > v.back()) {
            v.push_back(a[i]);
        } else {
            auto itr = lower_bound(v.begin(), v.end(), a[i]);
            *itr = a[i];
        }
    }
    cout << v.size();
    return 0;
}
