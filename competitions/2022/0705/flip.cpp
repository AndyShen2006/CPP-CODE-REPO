#include <bits/stdc++.h>

using namespace std;

int flip(int n)
{
    int temp = 0;
    while (n > 0) {
        temp *= 10;
        temp += n % 10;
        n /= 10;
    }
    return temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << min(flip(a), flip(b));
    return 0;
}