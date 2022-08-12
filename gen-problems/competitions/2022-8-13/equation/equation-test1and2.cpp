#include <bits/stdc++.h>

#include <utility>

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
            M.push_back(EmptyVector);
        }
        for (unsigned long i = 1; i <= n; i++) {
            for (unsigned long j = 0; j <= m; j++) {
                M[i].push_back(EmptyElement);
            }
        }
        cntRow = n;
        cntColumn = m;
    }
    matrix(unsigned long n, unsigned long m, long long val) // n行m列,并将所有元素初始化为val
    {
        for (unsigned long i = 0; i <= n; i++) {
            M.push_back(EmptyVector);
        }
        for (unsigned long i = 1; i <= n; i++) {
            for (unsigned long j = 0; j <= m; j++) {
                M[i].push_back(val);
            }
        }
        cntRow = n;
        cntColumn = m;
    }
    explicit matrix(vector<vector<long long>> I)
    {
        cntRow = I.size();
        cntColumn = I[0].size();
        M.push_back(EmptyVector);
        for (unsigned long i = 0; i < cntRow; i++) {
            M.push_back(EmptyVector);
            M[i + 1].push_back(EmptyElement);
            for (unsigned long j = 0; j < cntColumn; j++) {
                M[i + 1].push_back(I[i][j]);
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
                        ans.M[i][j] = (ans.M[i][j] % MOD + this->M[i][k] * rhs.M[k][j] % MOD) % MOD;
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

int main()
{
    long long n = 0;
    cin >> n;
    /*
    0 1 0 0
    1 0 1 0
    0 0 0 1
    1 0 0 0
    */
    if (n > 2) {
        vector<vector<long long>> mul {
            { 3, 1, 0 },
            { -2, 0, 0 },
            { 3, 0, 1 }
        }; // New feature in C++11:initalizer_list
        vector<vector<long long>> basic {
            { 2, 1, 1 }
        };
        matrix mmul(mul);
        matrix mbasic(basic);
        cout << mmul.quickpow(mbasic, n - 2).M[1][1] << endl;
    } else {
        cout << n << endl;
    }
    return 0;
}