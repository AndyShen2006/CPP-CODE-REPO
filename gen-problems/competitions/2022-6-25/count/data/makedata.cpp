#include <bits/stdc++.h>

using namespace std;

long long randint(long long from, long long to) // Interval[from,to]
{
    return rand() % (to - from + 1) + from;
}

void makeDataMain()
{
    cout << randint(1000000, 1000000000) * 1024 << endl;
}

int main()
{
    srand(time(0));
    string inputName, outputName;
    const string rawName = "count";
    for (int i = 8; i <= 10; i++) {
        inputName = rawName + (char)('0' + i) + ".in";
        freopen(inputName.c_str(), "w", stdout);
        makeDataMain();
        outputName = rawName + (char)('0' + i) + ".out";
        system("sleep 1");
        system(("../count < " + inputName + ">" + outputName).c_str());
    }
    return 0;
}