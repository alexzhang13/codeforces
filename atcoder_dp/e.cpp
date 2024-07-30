#include <iostream>

using namespace std;

const int MAXN = 101;
const int MAXV = 1e5+1;
const int MAXW = 1e9;

#define ll long long

ll dp[MAXN][MAXV];

int main(int argc, char* argv[]) {

  
  int N, W;
  cin >> N >> W;

  for (int i = 0; i <= N; i++) {
    for (int j = 1; j < MAXV; j++) {
      dp[i][j] = MAXW+1;
    }
  }
  
  ll wi, vi;
  for (int i = 1; i <= N; i++) {
    cin >> wi >> vi;
    for (int j = MAXV; j > 0; j--) {
      if (j-vi < 0) {
        dp[i][j] = dp[i-1][j];
        continue;
      }
      dp[i][j] = min(dp[i-1][j-vi] + wi, dp[i-1][j]);
    }
  }
  
  int v = 0;
  for (int j = MAXV-1; j >= 0; j--) {
    if (dp[N][j] <= W) {
      cout << j << endl;
      break;
    }
  }

  return 0;
}

