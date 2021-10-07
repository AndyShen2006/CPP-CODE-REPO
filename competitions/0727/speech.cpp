#include <bits/stdc++.h>

using namespace std;

int direct[30];

int main()
{
    freopen("speech.in", "r", stdin);
    freopen("speech.out", "w", stdout);
    string str;
    cin >> str;
    int n;
    cin >> n;
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        cin >> direct[c - 'A'];
    }
    for (int i = 0; i < str.size(); i++) {
        cout << direct[str[i] - 'A'];
    }
}