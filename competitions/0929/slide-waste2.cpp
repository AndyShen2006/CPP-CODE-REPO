#include <bits/stdc++.h>

using namespace std;

// Segmentation Tree
constexpr int MAX_N = 1 << 17;
int n, mindat[2 * MAX_N - 1], maxdat[2 * MAX_N - 1];

void init(int n_)
{
    n = 1;
    while (n < n_)
        n *= 2;
    for (int i = 0; i < 2 * n - 1; i++) {
        mindat[i] = INT_MAX;
        maxdat[i] = 0;
    }
}

void update(int k, int a)
{
    k += n - 1;
    mindat[k] = a;
    maxdat[k] = a;
    while (k > 0) {
        mindat[k] = min(mindat[k * 2 + 1], mindat[k + 2 + 2]);
        maxdat[k] = max(maxdat[k * 2 + 1], maxdat[k + 2 + 2]);
    }
}

int minquery(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) {
        return INT_MAX;
    }
    if (a <= l && r <= b) {
        return mindat[k];
    } else {
        int vl = minquery(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = minquery(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}
int maxquery(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) {
        return 0;
    }
    if (a <= l && r <= b) {
        return maxdat[k];
    } else {
        int vl = maxquery(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = maxquery(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
}
int main()
{
    int n, temp;
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        update(i, temp);
    }
    int ans;
    for (int i = 0; i < n; i++) {
        ans = 0;
        for (int j = 0; j < n - i; j++) {
            ans += minquery(j, j + i, 0, 0, n) * maxquery(j, j + i, 0, 0, n);
        }
        printf("%d ", ans);
    }
}