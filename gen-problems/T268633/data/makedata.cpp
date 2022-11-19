#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = 3 * randint(100000, 300000) * 3 + 1;
    for (int i = 1; i <= n; i++) {
        if (randint(0, 1)) {
            putchar('X');
        } else {
            putchar('O');
        }
    }
    putchar('\n');
    return 0;
}