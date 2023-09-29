// 矩阵快速幂！
#include <bits/stdc++.h>

using namespace std;

const vector<long long> EmptyVector;
const long long EmptyElement = 0;
constexpr long long MOD = 1e9 + 7;

struct matrix {
    vector<vector<long long>> M;
    unsigned long cntRow, cntColumn;
    matrix(unsigned long n, unsigned long m) // n行m列
    {
        for (unsigned long i = 0; i <= n; i++) {
            M.emplace_back(EmptyVector);
        }
        for (unsigned long i = 1; i <= n; i++) {
            for (unsigned long j = 0; j <= m; j++) {
                M[i].emplace_back(EmptyElement);
            }
        }
        cntRow = n;
        cntColumn = m;
    }
    matrix(unsigned long n, unsigned long m, long long val) // n行m列,并将所有元素初始化为val
    {
        for (unsigned long i = 0; i <= n; i++) {
            M.emplace_back(EmptyVector);
        }
        for (unsigned long i = 1; i <= n; i++) {
            for (unsigned long j = 0; j <= m; j++) {
                M[i].emplace_back(val);
            }
        }
        cntRow = n;
        cntColumn = m;
    }
    explicit matrix(vector<vector<long long>> I)
    {
        cntRow = I.size();
        cntColumn = I[0].size();
        M.emplace_back(EmptyVector);
        for (unsigned long i = 0; i < cntRow; i++) {
            M.emplace_back(EmptyVector);
            M[i + 1].emplace_back(EmptyElement);
            for (unsigned long j = 0; j < cntColumn; j++) {
                M[i + 1].emplace_back(I[i][j]);
            }
        }
    }
    static inline bool canMultiply(const matrix& A, const matrix& B)
    {
        if (A.cntColumn != B.cntRow) {
            return false;
        } else {
            return true;
        }
    }
    inline matrix operator*(const matrix& rhs) const
    {
        if (canMultiply(*this, rhs)) {
            matrix ans(this->cntRow, rhs.cntColumn);
            for (unsigned long i = 1; i <= ans.cntRow; i++) {
                for (unsigned long j = 1; j <= ans.cntColumn; j++) {
                    for (unsigned long k = 1; k <= this->cntColumn; k++) {
                        ans.M[i][j] = (ans.M[i][j] % MOD + ((this->M[i][k] % MOD) * (rhs.M[k][j] % MOD)) % MOD) % MOD;
                    }
                }
            }
            return ans;
        } else {
            return *this; // can't use multiply
        }
    }
    void showMatrix()
    {
        for (unsigned long i = 1; i <= cntRow; i++) {
            for (unsigned long j = 1; j <= cntColumn; j++) {
                cout << M[i][j] << ' ';
            }
            cout << endl;
        }
    }
    matrix quickpow(matrix base, long long x) const // M^x%mod
    {
        if (x > 0) {
            matrix res = std::move(base);
            matrix a = *this;
            while (x) {
                if (x & 1) {
                    res = res * a;
                }
                a = a * a;
                x >>= 1;
            }
            return res;
        } else {
            return base;
        }
    }
};

long long quickpow(long long base, int x)
{
    if (x == 0) {
        return 1;
    } else {
        base %= MOD;
        long long res = 1;
        long long a = base;
        while (x) {
            if (x & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            x >>= 1;
        }
        return res;
    }
}

int main()
{
    freopen("fat.in", "r", stdin);
    freopen("fat.out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    vector<vector<long long>> mul {
        { a, 1 },
        { b, 0 }
    }; // New feature in C++11:initalizer_list
    vector<vector<long long>> basic {
        { 1, 1 }
    };
    matrix mmul(mul);
    matrix mbasic(basic);
    long long k = mmul.quickpow(mbasic, n - 2).M[1][1];
    // mmul.quickpow(mbasic, n - 2).showMatrix();
    // cout << k << endl;
    cout << quickpow(m, k) << endl;
}