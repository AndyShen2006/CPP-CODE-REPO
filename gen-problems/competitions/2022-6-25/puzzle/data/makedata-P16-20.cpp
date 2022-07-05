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

vector<int> Ns;

int x = 5;
int m = 961;

void makeDataMain()
{
    int n = randint(100, 10000);
    int cnt = 0;
    int from, to, value;
    G.clear();
    // Bypass SPFA
    for (int i = 1; i <= 930; i++) {
        if (i % 31 == 0) {
            continue;
        }
        G[i].insert(i + 1);
        G[i + 1].insert(i);
        value = randint(1, 900000);
        printf("%d %d %d\n", i, i + 1, value);
        cnt++;
        G[i].insert(i + 31);
        G[i + 31].insert(i);
        value = randint(1, 900000);
        printf("%d %d %d\n", i, i + 31, value);
        cnt++;
        G[i].insert(i + 32);
        G[i + 32].insert(i);
        value = randint(1, 900000);
        printf("%d %d %d\n", i, i + 32, value);
        cnt++;
    }
    for (int i = 1; i <= 30; i++) {
        G[31 * i].insert(31 * (i + 1));
        G[31 * (i + 1)].insert(31 * i);
        value = randint(1, 900000);
        printf("%d %d %d\n", 31 * i, 31 * (i + 1), value);
        cnt++;
        G[30 * 31 + i].insert(30 * 31 + i + 1);
        G[30 * 31 + i + 1].insert(30 * 31 + i);
        value = randint(1, 900000);
        printf("%d %d %d\n", 30 * 31 + i, 30 * 31 + i + 1, value);
        cnt++;
    }
    // Random edges
    for (int i = 1; i <= n;) {
        from = randint(1, m);
        to = randint(1, m);
        value = randint(1, 900000);
        if (isValid(from, to)) {
            i++;
            G[from].insert(to);
            G[to].insert(from);
            printf("%d %d %d\n", from, to, value);
            cnt++;
        }
    }
    Ns.push_back(cnt);
}

int main()
{
    srand(time(0));
    string inputName, outputName;
    const string rawName = "puzzle";
    inputName = rawName + "20.in";
    freopen(inputName.c_str(), "w", stdout);
    cout << x << ' ' << m << endl;
    for (int i = 1; i <= 5; i++) {
        makeDataMain();
    }

    for (auto it : Ns) {
        cout << it << ' ';
    }
    // outputName = rawName + "10.out";
    //  system("sleep 1");
    //  system(("../puzzle < " + inputName + ">" + outputName).c_str());
    return 0;
}