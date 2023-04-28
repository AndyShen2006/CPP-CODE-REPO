#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    string seq;
    cin >> seq;
    if (~x & 1) {
        for (auto& it : seq) {
            it = it == '0' ? '1' : '0';
        }
    }
    cout << seq << endl;
    return 0;
}
