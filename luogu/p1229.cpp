#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    long long cnt = 0;
    for (int i = 0; i < s1.size() - 1; i++) {
        int loc = s2.find(s1[i]);
        if (s2[loc - 1] == s1[i + 1]) {
            cnt++;
        }
    }
    cout << (1 << cnt) << endl;
    return 0;
}