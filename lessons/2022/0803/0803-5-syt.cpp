#include <bits/stdc++.h>

using namespace std;

int a[10000], b[10000];
vector<int> v;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
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
