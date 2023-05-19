#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    double r;
    bool flag = false;
    cin >> m >> n >> r;
    int a = 0, b = 1, c = 1, d = 0; // a/b & c/d
    int e = 0, f = 0;
    double diff = r; // Difference between last result and current result
    int ansA = 0, ansB = 1;
    while (true) {
        e = a + c, f = b + d;
        if (e > m || f > n) {
            break;
        }
        double curDiff = fabs(1.0000 * e / f - r);
        if (curDiff == diff) {
            flag = true;
        }
        if (curDiff < diff) { // This result is better
            ansA = e, ansB = f, diff = curDiff, flag = false;
            if (diff == 0) { // No Difference
                break;
            }
        }
        if (1.0000 * e / f < r) { // Update
            a = e, b = f;
        } else {
            c = e, d = f;
        }
    }
    if (flag) {
        cout << "TOO MANY" << endl;
    } else {
        cout << ansA << '/' << ansB << endl;
    }
    return 0;
}