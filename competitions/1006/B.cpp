#include <bits/stdc++.h>

using namespace std;

vector<int> a;
map<int, int> M;

int main()
{
    int n, k;
    cin >> n >> k;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    do {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (a[i] < 10) {
                ans = ans * 10 + a[i];
            } else {
                ans = ans * 100 + a[i];
            }
        }
        M[ans] = 1;
    } while (next_permutation(a.begin(), a.end()));
    cout << M.size() << endl;
    return 0;
}
/*
5 3
11 11 11 11 11
*/