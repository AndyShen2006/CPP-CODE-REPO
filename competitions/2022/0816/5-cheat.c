#include <stdio.h>

struct Skill {
    int a, b, c;
} skills[100010];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    int flag;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &skills[i].a, &skills[i].b, &skills[i].c);
        flag = 1;
        for (int j = 1; j < i; j++) {
            if (skills[i].b == skills[j].b || skills[i].c == skills[j].c) {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    printf("%d\n", ans);
    return 0;
}