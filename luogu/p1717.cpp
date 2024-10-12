#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 110;
int fs[MAX_N], ds[MAX_N], ts[MAX_N], pret[MAX_N];

int main()
{
    // freopen("data/P3b.in", "r", stdin);
    int n, t;
    cin >> n >> t;
    t *= 60;
    for (int i = 1; i <= n; i++) {
        cin >> fs[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> ds[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> ts[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        pret[i] = pret[i - 1] + ts[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) { // 在第i个湖停下来
        int tmpT = t - pret[i - 1] * 5;
        int sum = 0;
        priority_queue<pair<int, int>> pq; // 记录可钓鱼量，在原序列中位置（用于定位减少量）
        for (int j = 1; j <= i; j++) { // 全部丢入堆中
            pq.emplace(fs[j], j);
        }
        while (tmpT > 0 && !pq.empty()) {
            auto p = pq.top(); // 取出该区间内最多可钓鱼数量
            pq.pop();
            sum += p.first;
            tmpT -= 5;
            if (p.first - ds[p.second] > 0) { // 仍然可以继续在该鱼塘钓鱼
                pq.emplace(p.first - ds[p.second], p.second); // 减去对应值后重新入堆
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}