#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(10000, 100000);
    int q = randint(10000, 100000);
    cout << n << ' ' << q << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(1, 10000) << ' ';
    }
    cout << endl;
    for (int i = 1; i <= q; i++) {
        int f = randint(1, n);
        int t = randint(f, n);
        cout << f << ' ' << t << endl;
    }
    return 0;
}