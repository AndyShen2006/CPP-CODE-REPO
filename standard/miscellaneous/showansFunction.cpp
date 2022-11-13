#include <bits/stdc++.h>

using namespace std;

void show(initializer_list<int> output)
{
    for (int it : output) {
        cout << it << ' ';
    }
    cout << endl;
}

int main()
{
    show({ 1, 2, 3, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 3, 3 });
    return 0;
}