#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for_each(s.begin(), s.end() - 1, [](char c) -> void {
        if (c != ' ') {
            cout << c - 'a' + 1;
        } else {
            cout << '#';
        }
    });
    cout << endl;
    return 0;
}