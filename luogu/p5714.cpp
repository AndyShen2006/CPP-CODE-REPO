#include <bits/stdc++.h>

using namespace std;

int main() {
  double m, h, ans;
  cin >> m >> h;
  ans = m / (h * h);
  if (ans < 18.5) {
    cout << "Underweight";
  } else if (ans >= 18.5 && ans < 24) {
    cout << "Normal";
  } else if (ans >= 24) {
    cout << ans << endl;
    cout << "Overweight";
  }
  return 0;
}