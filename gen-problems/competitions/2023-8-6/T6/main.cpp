#include <bits/stdc++.h>

using namespace std;

vector<int> mat;

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            mat.push_back(tmp);
        }
    }
    sort(mat.begin(), mat.end());
    for (int i = 1; i <= q; i++) {
        int v;
        cin >> v;
        cout << min(int(mat.end() - lower_bound(mat.begin(), mat.end(), v)), n) << endl;
    }
    return 0;
}