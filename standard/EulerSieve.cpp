#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10001;

int prime[MAX_N];
bool isVisit[MAX_N];

int main()
{
    int cnt = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!isVisit[i]) {
            cnt++;
            prime[cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] < MAX_N; j++) {
            isVisit[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return 0;
}