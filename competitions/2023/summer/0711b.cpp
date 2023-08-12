#include <bits/stdc++.h>

using namespace std;

int a[3010];

int main()
{
    int n, k;
    cin >> n >> k;
    long long cps = 0, zct = 0, rps = 0, lps = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cps += a[i];
        if (a[i] == 0) {
            zct++;
        }
    }
    long long eps = cps;
    if ((cps < 0 && cps + zct * k < 0) || (cps > 0 && cps - zct * k > 0)) {
        cout << "Yes!!!Zombies can't eat your brain!!!" << endl;
        exit(0);
    }
    vector<int> stk;
    if (cps > 0 && zct > 0) {
        zct--;
        while (cps > 0 && zct > 0) {
            cps -= k;
            zct--;
        }
        for (int i = 1; i <= zct / 2; i++) {
            stk.push_back(k);
        }
        if (zct & 1) {
            stk.push_back(k / 2);
        }
    } else if (cps < 0 && zct > 0) {
        zct--;
        while (cps < 0 && zct > 0) {
            cps += k;
            zct--;
        }
        for (int i = 1; i <= zct / 2; i++) {
            stk.push_back(k);
        }
        if (zct & 1) {
            stk.push_back(k / 2);
        }
    }
    cps = 0;
    if (eps >= 0) {
        int pos = 0;
        sort(stk.begin(), stk.end(), greater<>());
        for (int i = 0; i <= n; i++) {
            if (a[i] != 0) {
                cps += a[i];
            } else {
                cps += stk[pos++];
                rps = max(cps, rps);
            }
        }
    } else {
        int pos = 0;
        sort(stk.begin(), stk.end(), greater<>());
        for (int i = 0; i <= n; i++) {
            if (a[i] != 0) {
                cps += a[i];
            } else {
                cps -= stk[pos++];
                lps = min(cps, lps);
            }
        }
    }
    cout << rps << ' ' << lps << ' ' << zct << endl;
    cout << rps - lps + 1 << endl;
    return 0;
}