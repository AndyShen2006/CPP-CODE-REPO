#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, bs;
    int b, e;
    cin >> str >> b >> e;
    for (unsigned i = str.size() - b; i < str.size(); i++) {
        bs.push_back(str[i]);
    }
    for (unsigned i = e; i < str.size() - b; i++) {
        bs.push_back(str[i]);
    }
    for (int i = 0; i < e; i++) {
        bs.push_back(str[i]);
    }
    // cout << bs << endl;
    string num;
    bool sign = false; // false->alphabet,true->digit
    for (auto it : bs) {
        if (isdigit(it)) {
            sign = true;
            num.push_back(it);
        } else if (sign) {
            sign = false;
            cout << stoll(num) / 2;
            num.clear();
            cout << it;
        } else {
            cout << it;
        }
    }
    if (!num.empty()) {
        cout << stoll(num) / 2 << endl;
    }
    return 0;
}