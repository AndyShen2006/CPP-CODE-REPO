#include <bits/stdc++.h>

using namespace std;

set<int> seq;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        seq.insert(tmp);
    }
    int q;
    cin >> q;
    while (q--) {
        int tmp;
        cin >> tmp;
        if (seq.find(tmp) == seq.end()) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}