#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    int n = rand() % 1000;
    string s;
    for (int i = 1; i <= 6; i++) {
        char c = 'A' + rand() % 26;
        s.push_back(c);
    }
    cout << s << endl;
    s.clear();
    for (int i = 1; i <= 5; i++) {
        char c = 'A' + rand() % 26;
        s.push_back(c);
    }
    cout << s << endl;
    cout << n << endl;
    cout << s << endl;
    for (int i = 1; i <= n - 1; i++) {
        s.clear();
        for (int i = 1; i <= 6; i++) {
            char c = 'A' + rand() % 26;
            s.push_back(c);
        }
        cout << s << endl;
    }
    return 0;
}