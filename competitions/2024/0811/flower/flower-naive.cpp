#include <bits/stdc++.h>

using namespace std;

map<int, int> nums;
int lis[20];

int main()
{
    freopen("data/flowerN1.in", "r", stdin);
    freopen("data/flowerN1.ans", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> lis[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            nums[lis[i] + lis[j]]++;
        }
    }
    int cnt = 0;
    for (auto it : nums) {
        cerr << it.first << ' ' << it.second << endl;
        cnt += it.second;
        cerr << cnt << endl;
        if (cnt >= k) {
            cout << it.first << endl;
            exit(0);
        }
    }
    return 0;
}