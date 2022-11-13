#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, n;
    char symbol;
    cin >> a >> n;
    for (int i = 1; i <= n; i++) {
        cin >> symbol;
        switch (symbol) {
        case '+':
            a++;
            break;
        case '-':
            a--;
            break;
        case '*':
            a <<= 1;
            break;
        default:
            break;
        }
    }
    cout << a << endl;
    return 0;
}