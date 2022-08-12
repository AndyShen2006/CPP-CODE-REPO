#include <bits/stdc++.h>

using namespace std;

int a[100001];
int lazytag[100001];
int n, m;

int st[100001];

//[from,mid],[mid+1,to];mid=(from+to)/2

void build(int l, int r, int p) // Computing Interval[l,r], current node is p
{
    if (l == r) { // The size of this interval is 1, it's a single node
        st[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1; // compute middle node
    build(l, mid, p * 2); // build left tree
    build(mid + 1, r, p * 2 + 1); // build right tree
    st[p] = st[p * 2] + st[p * 2 + 1]; // Compute this value
}

int getsum(int l, int r, int curl, int curr, int p)
{
    // [l,r] is Interval I want to find
    // [curl,curr] is Interval of p
    if (l <= curl && curr <= r) {
        return st[p];
    }
    int mid = curl + ((curr - curl) >> 1);
    if (lazytag[p]) {
        st[p * 2] += lazytag[p] * (mid - curl + 1);
        st[p * 2 + 1] += lazytag[p] * (curr - mid);
        lazytag[p * 2] += lazytag[p];
        lazytag[p * 2 + 1] += lazytag[p];
        lazytag[p] = 0;
    }
    int ans = 0;
    if (l <= mid) {
        ans += getsum(l, r, curl, mid, p * 2);
    }
    if (mid < r) {
        ans += getsum(l, r, mid + 1, curr, p * 2 + 1);
    }
    return ans;
}

void update(int l, int r, int curl, int curr, int p, int c)
{
    if (l <= curl && curr <= r) {
        st[p] += (curr - curl + 1) * c;
        lazytag[p] += c;
        return;
    }
    int mid = curl + ((curr - curl) >> 1);
    if (lazytag[p] && curl != curr) { // Still have lazy tag which hasn't computed
        st[p * 2] += lazytag[p] * (mid - curl + 1);
        st[p * 2 + 1] += lazytag[p] * (curr - curl);
        lazytag[p * 2] += lazytag[p];
        lazytag[p * 2 + 1] += lazytag[p];
        lazytag[p] = 0; // This lazy tag has computed
    }
    if (l <= mid) {
        update(l, r, curl, mid, p * 2, c);
    }
    if (r > m) {
        update(l, r, mid + 1, curr, p * 2 + 1, c);
    }
    st[p] = st[p * 2] + st[p * 2 + 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    update(1, 3, 1, n, 1, 3);
    update(2, 4, 1, n, 1, 2);
    cout << getsum(1, 4, 1, n, 1) << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << ' ' << st[i] << ' ' << lazytag[i] << endl;
    }
    /*
    1 5 4 2 3
    4 8 7 2 3
    6 10 9 4 3  29!
    int op = 0, x, y, k;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(x, y, 1, n, 1, k);
        } else {
            cin >> x >> y;
            cout << getsum(x, y, 1, n, 1) << endl;
        }
    }
    */
    return 0;
}