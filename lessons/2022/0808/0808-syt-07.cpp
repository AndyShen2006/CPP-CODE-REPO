#include <bits/stdc++.h>

#include <utility>

using namespace std;

const vector<int> EmptyVector;
const int EmptyElement = 0;
constexpr int MOD = 1000;
struct matrix {
    vector<vector<int>> M;
    unsigned long cntRow, cntColumn;
    matrix(unsigned long n, unsigned long m) // n行m列
    {
        for (int i = 0; i <= n; i++) {
            M.push_back(EmptyVector);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                M[i].push_back(EmptyElement);
            }
        }
        cntRow = n;
        cntColumn = m;
    }
    matrix(unsigned long n, unsigned long m, int val) // n行m列,并将所有元素初始化为val
    {
        for (int i = 0; i <= n; i++) {
            M.push_back(EmptyVector);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                M[i].push_back(val);
            }
        }
        cntRow = n;
        cntColumn = m;
    }
    explicit matrix(vector<vector<int>> I)
    {
        M = I;
        cntRow = I.size() - 1;
        cntColumn = I[0].size() - 1;
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
            for (int i = 1; i <= ans.cntRow; i++) {
                for (int j = 1; j <= ans.cntColumn; j++) {
                    for (int k = 1; k <= this->cntColumn; k++) {
                        ans.M[i][j] = (ans.M[i][j] + this->M[i][k] * rhs.M[k][j]) % MOD;
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
        for (int i = 1; i <= cntRow; i++) {
            for (int j = 1; j <= cntColumn; j++) {
                cout << M[i][j] << ' ';
            }
            cout << endl;
        }
    }
    matrix quickpow(matrix base, int x) const // M^x%mod
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
    int n;
    cin >> n;
    /*
    0 1 0 0
    1 0 1 0
    0 0 0 1
    1 0 0 0
    */
    if (n > 4) {
        vector<vector<int>> mul {
            { 0, 0, 0, 0, 0 }, //填空用的
            { 0, 0, 1, 0, 0 },
            { 0, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 1 },
            { 0, 1, 0, 0, 0 }
        }; // New feature in C++11:initalizer_list
        vector<vector<int>> basic {
            { 0, 0, 0, 0, 0 },
            { 0, 4, 3, 2, 1 }
        };
        matrix mmul(mul);
        matrix mbasic(basic);
        cout << mmul.quickpow(mbasic, n - 4).M[1][1] << endl;
    } else {
        cout << n << endl;
    }
    return 0;
}