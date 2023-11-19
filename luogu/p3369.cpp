#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <experimental/random>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> rbt;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int opt;
        ll x;
        cin >> opt >> x;
        switch (opt) {
        case 1:
            rbt.insert((x << 20) + i);
            break;
        case 2:
            rbt.erase(rbt.lower_bound(x << 20));
            break;
        case 3:
            cout << rbt.order_of_key(x << 20) + 1 << endl;
            break;
        case 4:
            cout << (*rbt.find_by_order(x - 1) >> 20) << endl;
            break;
        case 5:
            cout << ((*--rbt.lower_bound(x << 20)) >> 20) << endl;
            break;
        case 6:
            cout << ((*rbt.upper_bound((x << 20) + n)) >> 20) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}