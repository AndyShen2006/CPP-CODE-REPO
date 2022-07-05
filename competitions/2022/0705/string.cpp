#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (auto& it : s) {
        if (islower(it)) {
            it = toupper(it);
        } else {
            it = tolower(it);
        }
    }
    for (int i = 1; i < s.size(); i++) {
        cout << s[i];
    }
    cout << s[0] << endl;
    return 0;
}