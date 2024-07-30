#include <iostream>

using namespace std;

#define ll long long

const int MAXN = 1e2 + 1;
const int MAXW = 1e5 + 1;
ll dp[MAXN][MAXW];

int main() {
  int n, w;
  cin >> n >> w;
  
  int wi, vi;

  for (int i = 1; i <= n; i++) {
    cin >> wi >> vi;
    for (int j = 0; j <= w; j++) {
      dp[i][j] = dp[i-1][j];
      if (j >= wi) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-wi] + vi);
      }
    }    
  }  
  
  cout << dp[n][w] << endl;

  return 0;
}
