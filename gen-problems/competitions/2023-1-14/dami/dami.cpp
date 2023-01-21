#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> grp;

int main()
{
    // freopen("data/dami1.in","r",stdin);
    int a;
    cin >> a;
    int n;
    string str;
    bool flag;
    for (int i = 1; i <= a; i++) {
        flag = false;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> str;
            if (str.find("bie") != string::npos && !grp[str]) {
                grp[str] = true;
                flag = true;
                cout << str << '\n';
            }
        }
        if (!flag) {
            cout << "Time to play Genshin Impact, Teacher Rice!\n";
        }
    }

    return 0;
}