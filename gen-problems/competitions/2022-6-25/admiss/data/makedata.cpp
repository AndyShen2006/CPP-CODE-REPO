#include <bits/stdc++.h>

using namespace std;

constexpr int nodes_num = 10;

int randint(int from, int to) // Interval[from,to]
{
    return rand() % (to - from + 1) + from;
}

string randStr(int length)
{
    string tempStr;
    for (int i = 1; i <= length; i++) {
        switch (rand() % 3) {
        case 0:
            tempStr.push_back('a' + rand() % 26);
            break;
        case 1:
            tempStr.push_back('A' + rand() % 26);
            break;
        case 2:
            tempStr.push_back('0' + rand() % 10);
            break;
        default:
            break;
        }
    }
    return tempStr;
}

void makeDataMain()
{
    vector<string> School_names;
    int m = randint(1, 30);
    int n = randint(1, 1000);
    int a = randint(1, 20);
    int low = randint(540, 570);
    int score;
    printf("%d %d %d %d\n", m, n, a, low);
    string tempStr;
    for (int i = 1; i <= m; i++) {
        tempStr = randStr(30);
        cout << tempStr << ' ' << randint((n / m - 30 >= 1 ? n / m : 1), n / m) << endl;
        School_names.push_back(tempStr);
    }
    string name;
    for (int i = 1; i <= n; i++) {
        name = randStr(8);
        cout << name << endl;
        score = randint(540, 570);
        cout << score << endl;
        for (int j = 1; j <= a; j++) {
            cout << School_names[randint(0, m - 1)] << endl;
        }
    }
}

int main()
{
    srand(time(0));
    string inputName, outputName;
    const string rawName = "admiss";
    for (int i = 1; i <= nodes_num; i++) {
        inputName = rawName + (char)('0' + i) + ".in";
        freopen(inputName.c_str(), "w", stdout);
        makeDataMain();
        outputName = rawName + (char)('0' + i) + ".out";
        system("sleep 1");
        system(("../admiss < " + inputName + ">" + outputName).c_str());
    }
    return 0;
}