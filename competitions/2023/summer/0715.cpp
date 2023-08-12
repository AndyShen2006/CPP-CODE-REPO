#include <bits/stdc++.h>

constexpr int MOD = 998244353;
using namespace std;
int n, m, s, q;

/*
    Matrix Implementation by Andy Shen
*/

struct Matrix {
    int _head[1010][1010] = { { 0 } };

    inline void NaiveMultiply(const Matrix& rhs)
    {
        Matrix ans;
        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 1; j <= n; j++) {
                for (size_t k = 1; k <= n; k++) {
                    ans.modify(i, j, (ans.at(i, j) + (this->at(i, k) * rhs.at(k, j) % MOD)) % MOD);
                }
            }
        }
        memcpy(_head, ans._head, sizeof(ans._head));
    }

    // Construction Functions
    Matrix()
        = default;

    Matrix(Matrix const& M)
    {
        n = n;
        n = n;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                _head[i][j] = M._head[i][j];
            }
        }
    }

    // IO Functions
    inline int at(size_t r, size_t c) const
    {
        return _head[r - 1][c - 1];
    }
    inline void modify(size_t r, size_t c, int val)
    {
        _head[r - 1][c - 1] = val;
    }
    void show()
    {
        cout << "test" << endl;
        cout << n << ' ' << n << endl;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                std::cout << _head[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    inline void quickPow(Matrix& Ans, size_t x) const
    {
        if (x > 0) {
            auto a(*this);
            while (x) {
                if (x & 1) {
                    Ans.NaiveMultiply(a);
                }
                a.NaiveMultiply(a);
                x >>= 1;
            }
        } else {
            return;
        }
    }
};

Matrix G;
Matrix ans;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.modify(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        ans.modify(i, i, 1);
    }
    G.quickPow(ans, s);
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        cout << ans.at(u, v) << endl;
    }
    return 0;
}