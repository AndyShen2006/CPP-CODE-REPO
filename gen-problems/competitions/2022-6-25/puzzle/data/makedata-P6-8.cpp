#include <bits/stdc++.h>

using namespace std;

long long randint(long long from, long long to) // Interval[from,to]
{
    return rand() % (to - from + 1) + from;
}

map<int, set<int>> G;

bool isValid(int from, int to)
{
    return from != to && G[from].find(to) == G[from].end();
}

void makeDataMain()
{
    int x = 1;
    int m = randint(50, 100);
    cout << x << ' ' << m << endl;
    int n = randint(100, 1000);
    cout << n << endl;
    int from, to, value;
    for (int i = 1; i <= n;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 90000);
        if (isValid(from, to)) {
            i++;
            G[from].insert(to);
            G[to].insert(from);
            printf("%d %d %d\n", from, to, value);
        }
    }
}

int main()
{
    srand(time(0));
    string inputName, outputName;
    const string rawName = "puzzle";
    for (int i = 6; i <= 8; i++) {
        inputName = rawName + (char)('0' + i) + ".in";
        freopen(inputName.c_str(), "w", stdout);
        makeDataMain();
        outputName = rawName + (char)('0' + i) + ".out";
        system("sleep 1");
        system(("../puzzle < " + inputName + ">" + outputName).c_str());
    }
    return 0;
}