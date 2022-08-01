#include <bits/stdc++.h>

using namespace std;

bool isDel[10000001];
string str;

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < n - 1; i++) {
        if (str[i] < str[i + 1]) {
            isDel[i] = true;
            cnt++;
        }
        if (cnt == m) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!isDel[i]) {
            putchar(str[i]);
        }
    }
    return 0;
}