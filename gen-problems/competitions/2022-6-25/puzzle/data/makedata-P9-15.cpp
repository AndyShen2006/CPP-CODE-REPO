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
    int x = 5;
    int m = randint(100, 1000);
    cout << x << ' ' << m << endl;
    int n1 = randint(2000, min(m * (m - 5), 100000));
    int n2 = randint(2000, min(m * (m - 5), 100000));
    int n3 = randint(2000, min(m * (m - 5), 100000));
    int n4 = randint(2000, min(m * (m - 5), 100000));
    int n5 = randint(2000, min(m * (m - 5), 100000));
    printf("%d %d %d %d %d\n", n1, n2, n3, n4, n5);
    int from, to, value;
    for (int i = 1; i <= n1;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 900000);
        if (isValid(from, to)) {
            i++;
            G[from].insert(to);
            G[to].insert(from);
            printf("%d %d %d\n", from, to, value);
        }
    }
    G.clear();
    for (int i = 1; i <= n2;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 900000);
        if (isValid(from, to)) {
            i++;
            G[from].insert(to);
            G[to].insert(from);
            printf("%d %d %d\n", from, to, value);
        }
    }
    G.clear();
    for (int i = 1; i <= n3;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 900000);
        if (isValid(from, to)) {
            i++;
            G[from].insert(to);
            G[to].insert(from);
            printf("%d %d %d\n", from, to, value);
        }
    }
    G.clear();
    for (int i = 1; i <= n4;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 900000);
        if (isValid(from, to)) {
            i++;
            G[from].insert(to);
            G[to].insert(from);
            printf("%d %d %d\n", from, to, value);
        }
    }
    G.clear();
    for (int i = 1; i <= n5;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 900000);
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
    inputName = rawName + "15.in";
    freopen(inputName.c_str(), "w", stdout);
    makeDataMain();
    // outputName = rawName + "10.out";
    //  system("sleep 1");
    //  system(("../puzzle < " + inputName + ">" + outputName).c_str());
    return 0;
}