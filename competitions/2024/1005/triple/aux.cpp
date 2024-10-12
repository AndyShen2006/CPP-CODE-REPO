#include <bits/stdc++.h>

using namespace std;

int gcd(initializer_list<int> il)
{
    int ans = *il.begin();
    for (auto it : il) {
        ans = __gcd(ans, it);
    }
    return ans;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (gcd({ a * b, a * c, b * c }) * gcd({ a * a, b * b, c * c })) / (gcd({ a * b * b, a * c * c, b * c * c, b * a * a, c * a * a, c * b * b }) * gcd({ a, b, c })) << endl;
    return 0;
}