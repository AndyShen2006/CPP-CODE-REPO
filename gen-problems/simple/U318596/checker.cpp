#include <bits/stdc++.h>
#include <testlib.h>

static std::random_device rand_dev; // NOLINT
static std::mt19937_64 rand_eng(rand_dev()); // NOLINT

class doubleRand {
public:
    double operator()(double start, double end)
    {
        std::uniform_real_distribution<double> u(start, end);
        return u(rand_eng);
    }
} randdouble;

class intRand {
public:
    int operator()(int start, int end)
    {
        std::uniform_int_distribution<signed int> u(start, end);
        return u(rand_eng);
    }
} randint;

using namespace std;

int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = randint(1, 50);
    int score = INT_MAX;
    cout << t << endl;
    while (t--) {
        int m = randint(200, 10000), n = randint(290, 10000);
        int rest = randint(1, 9);
        double r = ((int)(randdouble(((m - randint(10, 20)) * 1.0) / ((n + randint(10, 20)) * 1.0), ((m + randint(10, 20)) * 1.0) / ((n - randint(10, 20)) * 1.0)) * pow(10, rest))) / pow(10, rest);
        cout << m << ' ' << n << endl;
        cout << r << endl;
        bool flag = false;
        int a = 0, b = 1, c = 1, d = 0; // a/b & c/d
        int e = 0, f = 0;
        double diff = r; // Difference between last result and current result
        int ansA = 0, ansB = 1;
        while (true) {
            e = a + c, f = b + d;
            if (e > m || f > n) {
                break;
            }
            double curDiff = fabs(1.0000 * e / f - r);
            if (curDiff == diff) {
                flag = true;
            }
            if (curDiff < diff) { // This result is better
                ansA = e, ansB = f, diff = curDiff, flag = false;
                if (diff == 0) { // No Difference
                    break;
                }
            }
            if (1.0000 * e / f < r) { // Update
                a = e, b = f;
            } else {
                c = e, d = f;
            }
        }
        if (flag) {
            string pans;
            cin >> pans;
            if (pans != "Respect, Chongzhi Zu") {
                quitf(_wa, "The answer is wrong.");
            }
        } else {
            int pansA;
            int pansB;
            double pansR;
            cin >> pansA >> pansB >> pansR;
            double ansR = fabs((ansA * 1.0) / (ansB * 1.0) - r);
            if (fabs(fabs((pansA * 1.0) / (pansB * 1.0) - r) - pansR) > 0.00001) {
                quitf(_wa, "Your u/v is not equal to your r, you maybe cheat the checker.%.11lf", fabs(fabs((pansA * 1.0) / (pansB * 1.0) - r) - pansR));
            }
            if (fabs(pansR - ansR) > 0.00001) {
                score = min(score, (int)log10(fabs(pansR - ansR)) * (-20));
            }
        }
    }
    if (score >= 100) {
        quitf(_ok, "Your answer is correct!, score:%d", score);
    } else {
        quitp((score / 100.0), "Your answer is partially correct. You will get %d percent", score);
    }
    return 0;
}