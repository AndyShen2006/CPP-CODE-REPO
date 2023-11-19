#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;

struct Rational {
    typedef __int128 T;
    T p, q; // p/q
    Rational() = default;
    Rational(T x, T y)
    {
        p = x;
        q = y;
    }
    explicit Rational(int x)
    {
        p = x;
        q = 1;
    }
    Rational operator+(const Rational& rhs) const
    {
        T l = lcm(q, rhs.q);
        T rlq = l / rhs.q, rrq = l / q;
        Rational tmp(0, l);
        tmp.p += p * rrq;
        tmp.p += rhs.p * rlq;
        tmp.simplify();
        return tmp;
    }
    Rational operator/(const int& rhs) const
    {
        Rational tmp(p, q * rhs);
        tmp.simplify();
        return tmp;
    }
    bool operator<(const Rational& rhs) const
    {
        T l = lcm(q, rhs.q);
        T rlq = l / rhs.q, rrq = l / q;
        return p * rrq < rhs.p * rlq;
    }
    void show() const
    {
        print(p);
        cout << ' ';
        print(q);
        cout << endl;
    }

private:
    static T lcm(T p, T q)
    {
        return (p / gcd(p, q)) * q;
    }
    static T gcd(T p, T q)
    {
        return __gcd(p, q);
    }
    static void print(T x)
    {
        string tmp;
        if (x == 0) {
            cout << 0;
            return;
        }
        while (x > 0) {
            tmp.push_back(char('0' + x % 10));
            x /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp;
    }
    void simplify()
    {
        T g = gcd(p, q);
        p /= g;
        q /= g;
    }
};

int d[MAX_N];
Rational cur[MAX_N];
vector<int> G[MAX_N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        for (int j = 1; j <= d[i]; j++) {
            int v;
            cin >> v;
            G[i].push_back(v);
        }
    }
    queue<int> Q;
    for (int i = 1; i <= m; i++) {
        cur[i] = { 1, 1 };
        Q.push(i);
    }
    for (int i = m + 1; i <= n; i++) {
        cur[i] = { 0, 1 };
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (d[u] == 0) {
            continue;
        }
        Rational per = cur[u] / d[u];
        cur[u] = { 0, 1 };
        for (auto it : G[u]) {
            cur[it] = cur[it] + per;
            Q.push(it);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            cur[i].show();
        }
    }
    return 0;
}