#include <bits/stdc++.h>

using namespace std;

const vector<int> EmptyVector;
const int EmptyElement = 0;
struct matrix {
    vector<vector<int>> M;
    int cntRow, cntColumn;
    matrix(int n, int m) // n行m列
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
    matrix(int n, int m, int val) // n行m列,并将所有元素初始化为val
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
                        ans.M[i][j] += this->M[i][k] * rhs.M[k][j];
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
    matrix quickpow(int x) const // M^x%mod
    {
        matrix res(cntRow, cntColumn, 1);
        matrix a = *this;
        while (x) {
            if (x & 1) {
                res = res * a;
            }
            a = a * a;
            x >>= 1;
        }
        return res;
    }
};

int main()
{
    freopen("data/matrix2.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    matrix m(n, n);
    int val;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> val;
            m.M[i][j] = val;
        }
    }
    m.quickpow(k).showMatrix();
    return 0;
}