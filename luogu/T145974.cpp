#include<bits/stdc++.h>

using namespace std;

const unsigned long long mod = 1145141;

typedef unsigned long long int ull;

ull gcd(ull a, ull b)
{
    if(a == 0)  return b;
    else if(b == 0)  return a; 
    else return b ? gcd(b, a % b) : a;
}

ull quickpow(ull x, ull n)
{
    if(x == 0)  return 0;
    ull res = 1;
    while(n > 0) {
        if(n & 1)  res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

map<int, ull> data;

int main()
{
    string s;
    cin >> s;
    ull sLen = s.size();
    for(int i=0; i<=9; i++) {
        data[i] = 0;
        for(auto it : s) {
            if(it - '0' == i) {
                data[i]++;
            }
        }
    }
    int ans=0;
    for(int i=0; i<=8; i++) {
        //printf("%d %d %d %d\n",i, data[i], gcd(data[i], data[i+1]), quickpow(gcd(data[i], data[i+1]), sLen));
        ans += quickpow(gcd(data[i], data[i+1]), sLen);
    }
    ans = ans % mod;
    cout << ans << endl;
    return 0;
}
