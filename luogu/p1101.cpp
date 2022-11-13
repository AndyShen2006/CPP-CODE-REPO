#include <bits/stdc++.h>

using namespace std;

char matrix[101][101];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }
  return 0;
}