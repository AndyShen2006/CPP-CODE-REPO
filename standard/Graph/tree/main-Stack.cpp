#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, set<int>> T;

int main()
{
    freopen("data1.in", "r", stdin);
    freopen("data1.out", "w", stdout);
    int n;
    cin >> n;
    int tempA, tempB;
    for (int i = 0; i < n; i++) {
        cin >> tempA >> tempB;
        T[tempA].insert(tempB);
        T[tempB].insert(tempA);
    }
    return 0;
}