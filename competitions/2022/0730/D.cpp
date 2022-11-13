#include <bits/stdc++.h>

using namespace std;

vector<string> G;

int main()
{
    int s;
    cin >> s;
    int n, m;
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        G.push_back(str);
    }
    return 0;
}