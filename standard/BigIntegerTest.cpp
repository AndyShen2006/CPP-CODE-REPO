#include <bits/stdc++.h>

using namespace std;

class BigInteger {
public:
    typedef char uint8;
    vector<uint8> data;
    BigInteger(string str)
    {
        for (string::iterator it; it = str.begin(); it++) {
            data.push_back(&it - '0');
        }
    }
    static string toStr(BigInteger a)
    {
        string tempStr;
        for (auto it : a.data) {
        }
        tempStr.push_back();
    }

private:
    BigInteger add(BigInteger a, BigInteger b)
    {
        BigInteger ar = a, br = b;
    }
};

int main()
{

    return 0;
}