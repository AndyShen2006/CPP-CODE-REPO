#include <cstdio>
#include <iostream>

using namespace std;

double sum;

int main()
{
    // freopen("data/test.txt", "w", stdout);
    // freopen("data/data2.in", "r", stdin);
    // freopen("data/data2.out", "w", stdout);
    double n;
    cin >> n;
    double tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        sum += tmp;
    }
    sum /= n + 1;
    printf("%.2lf ", sum * 2);
    for (int i = 1; i <= n - 1; i++) {
        printf("%.2lf ", sum);
    }
    printf("\n");
    return 0;
}