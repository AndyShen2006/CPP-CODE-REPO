#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
    decltype(5) a;
    cin >> a;
    cout << a;
    for(int & it : v) {
        cout << it;
    }
    return 0;
}
