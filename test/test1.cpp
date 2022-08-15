#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
int a;
__gnu_pbds::priority_queue<int> q;
struct Node {
    int a, b;
    Node(int _a, int _b)
        : a(_a)
        , b(_b)
    {
    }
};

vector<int> v;

int main()
{
    cerr << 2 << endl;
    cout << 3 << endl;
    printf("%d", 2);
    v.push_back(2);
    auto a = unique(v.begin(), v.end());
    return 0;
}
