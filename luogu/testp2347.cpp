#include <bitset>
#include <cstdio>
int a[10], w[10] = {1, 2, 3, 5, 10, 20};
std::bitset<1010> S;
int main() {
    for(int i = 0; i < 6; i++) scanf("%d", a + i);
    S[0] = 1;
    for(int i = 0; i < 6; i++) for(int j = 0; j < a[i]; j++) S |= S << w[i];
    printf("Total=%d\n", S.count() - 1);
    return 0;
}
