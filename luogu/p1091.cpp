#include <iostream>
#include <vector>

using namespace std;

int a[10000], b[10000], c[10000];
vector<int> v, u;

int main()
{
    //freopen("data/p1091b.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //    printf("push %d\n", a[0]);
    v.push_back(a[0]);
    b[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > v.back()) {
            //            printf("push %d\n", a[i]);
            v.push_back(a[i]);
            b[i] = v.size();
        } else {
            auto itr = lower_bound(v.begin(), v.end(), a[i]);
            //            printf("replace %d to %d\n", *itr, a[i]);
            b[i] = itr - v.begin() + 1;
            *itr = a[i];
        }
    }
    /*
    cout << v.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
    */
    u.push_back(a[n - 1]);
    c[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > u.back()) {
            //            printf("push %d\n", a[i]);
            u.push_back(a[i]);
            c[i] = u.size();
        } else {
            auto itr = lower_bound(u.begin(), u.end(), a[i]);
            //            printf("replace %d to %d\n", *itr, a[i]);
            c[i] = itr - u.begin() + 1;
            *itr = a[i];
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
    */
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max(sum, b[i] + c[i]);
    }
    cout << n - sum + 1 << endl;
    return 0;
}
