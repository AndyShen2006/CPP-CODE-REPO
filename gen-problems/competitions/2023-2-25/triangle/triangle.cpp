#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long m, n;
    cin >> m >> n;
    vector<long long> temp = { 2 * m * n, m * m - n * n, m * m + n * n };
    sort(temp.begin(), temp.end());
    cout << temp[0] << ' ' << temp[1] << ' ' << temp[2] << endl;
    return 0;
}