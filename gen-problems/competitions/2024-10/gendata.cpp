#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int numN = randint(50, 100);
    int opN = numN - 1;
    int numCnt = 0, opCnt = 0;
    cout << numN + opN << endl;
    while (numN + opN > 0) {
        if (numCnt > opCnt + 1) {
            bool op = randint(0, 1);
            if (op) {
                cout << randint(1, 10) << endl;
                numCnt++;
                numN--;
            } else {
                int type = randint(0, 2);
                switch (type) {
                case 0:
                    cout << '+' << endl;
                    break;
                case 1:
                    cout << '-' << endl;
                    break;
                case 2:
                    cout << '*' << endl;
                    break;
                default:
                    break;
                }
                opCnt++;
                opN--;
            }
        } else {
            cout << randint(1, 10) << endl;
            numCnt++;
            numN--;
        }
    }
    return 0;
}