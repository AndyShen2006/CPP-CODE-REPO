#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

double judge(string jans, const string& pans, initializer_list<double> score)
{
    if (jans.size() != pans.size()) {
        quitf(_fail, "Your format is incorrect.");
    }
    double total = 0;
    int pos = 0;
    for (auto it : score) {
        total += (jans[pos] == pans[pos]) * it;
        pos++;
    }
    return total;
}

int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
    string pans = ouf.readToken();
    double score = judge("BDDACCCBABDABBB", pans, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 });
    if (score == 30) {
        quitf(_ok, "Your answer is completely correct.");
    } else {
        quitp(score / 30.0, "Your answer is partially correct.");
    }
    return 0;
}