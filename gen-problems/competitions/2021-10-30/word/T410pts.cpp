#include <bits/stdc++.h>

using namespace std;

int main()
{
    string start, end;
    cin >> start >> end;
    if (start[start.size() - 1] == end[0]) {
        cout << 1 << endl;
        cout << start << " -> " << end << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}