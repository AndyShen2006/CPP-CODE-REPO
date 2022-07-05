#include <bits/stdc++.h>

using namespace std;

constexpr int nodes_num = 10;

int randint(int from, int to) // Interval[from,to]
{
    return rand() % (to - from + 1) + from;
}

vector<int> G[100001];
int keybind[100001];

void makeDataMain()
{
    const int N = randint(50000, 100000);
    const int M = randint(105000, 400000);
    printf("%d %d\n", N, M);
    int from, to;
    for (int i = 1; i <= M; i++) {
        do {
            from = randint(1, N);
            to = randint(1, N);
        } while (from < to);
        G[from].push_back(to);
    }
    for (int i = 1; i <= N; i++) {
        keybind[i] = i;
    }
    random_shuffle(keybind + 1, keybind + N + 1);
    for (int i = 1; i <= N; i++) {
        for (auto it : G[i]) {
            printf("%d %d\n", keybind[i], keybind[it]);
        }
    }
}

int main()
{
    srand(time(0));
    string inputName, outputName;
    const string rawName = "chain";
    for (int i = 1; i <= nodes_num; i++) {
        inputName = rawName + (char)('0' + i) + ".in";
        freopen(inputName.c_str(), "w", stdout);
        makeDataMain();
        outputName = rawName + (char)('0' + i) + ".out";
        system("sleep 1");
        system(("../chain < " + inputName + ">" + outputName).c_str());
    }
    return 0;
}