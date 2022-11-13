#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
const string jans1 = "FTFTAD";
const string jans2 = "FTTFDB";
const string jans3 = "TTACDD";

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
    string pans1 = ouf.readToken();
    string pans2 = ouf.readToken();
    string pans3 = ouf.readToken();
    double total = judge(jans1, pans1, { 1.5, 1.5, 1.5, 1.5, 3, 3 }) + judge(jans2, pans2, { 1.5, 1.5, 1.5, 1.5, 3, 3 }) + judge(jans2, pans2, { 2, 2, 3, 3, 3, 3 });
    if (total == 40) {
        quitf(_ok, "Your answer is completely correct.");
    } else {
        quitp(total / 40.0, "Your answer is partially correct.");
    }
    return 0;
}