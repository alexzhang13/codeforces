#include <iostream>
#include <vector>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> a(N, vector<int>(N, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
    }
  }

  for (int m = 1; m <= N; m++) {
    for (int s = 0; s < (1 << N); s++) {
      
    }
  }

  return 0;
}
