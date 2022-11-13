#include <bits/stdc++.h>

using namespace std;

struct matrix {
    vector<vector<int>> M;
    const vector<int> EmptyVector;
    const int EmptyElement = 0;
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
};

int main()
{
    freopen("data/matrix1.in", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    matrix m1(a, b);
    matrix m2(b, c);
    int val;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> val;
            m1.M[i][j] = val;
        }
    }
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> val;
            m2.M[i][j] = val;
        }
    }
    (m1 * m2).showMatrix();
    return 0;
}