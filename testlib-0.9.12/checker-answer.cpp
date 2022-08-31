#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int judge(string jans, const string& pans, initializer_list<int> score)
{
    if (jans.size() != pans.size()) {
        quitf(_fail, "Your format is incorrect");
    }
    int total = 0;
    int pos = 0;
    for (auto it : score) {
        total += (jans[pos] == pans[pos]) * it;
        pos++;
    }
    return total;
}

int main(int argc, char** argv)
{
    cout << judge("ABCDA", "ABCDD", { 3, 3, 3, 3, 3 }) << endl;
    return 0;
}