#include <bits/stdc++.h>

// Hanoi,use function instead.

using namespace std;

void move(int siz, char src, char dest)
{
    cout << "move " << siz << " from " << src << " to " << dest << endl;
}

void hanoi(int level, int cur, char src, char dest, char cache)
{
    if (level <= 1) {
        move(cur, src, dest);
        return;
    }
    hanoi(level - 1, cur - 1, src, cache, dest);
    hanoi(1, cur, src, dest, cache);
    hanoi(level - 1, cur - 1, cache, dest, src);
}

int main()
{
    int n;
    char A, B, C;
    cin >> n >> A >> B >> C;
    hanoi(n, n, A, C, B);
    return 0;
}