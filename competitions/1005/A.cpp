#include <bits/stdc++.h>

using namespace std;

vector<string> names;
vector<int> nums;

int main()
{
    int n;
    cin >> n;
    string ts;
    int tn;
    for (int i = 1; i <= n; i++) {
        cin >> ts;
        names.push_back(ts);
    }
    for (int i = 1; i <= n; i++) {
        cin >> tn;
        nums.push_back(tn);
    }
    sort(names.begin(), names.end());
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        cout << names[i] << ' ' << nums[i] << endl;
    }
    return 0;
}
/*
5
src
oldway
claire
whqsdhr
ylq
89757
20091111
130203
8000800
1008611
*/