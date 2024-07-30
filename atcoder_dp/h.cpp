#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int H, W;
  cin >> H >> W;

  vector<vector<ll>> dp(H+1, vector<ll>(W+1));
  dp[1][1] = 1;
  
  char c;
  for (auto h = 1; h <= H; h++) {
    for (auto w = 1; w <= W; w++) {
      cin >> c;
      // grid[h][w] = c;
      if (c == '.') {
        if (w > 1)
          dp[h][w] = (dp[h][w] + dp[h][w-1]) % MOD;
        if (h > 1)
          dp[h][w] = (dp[h][w] + dp[h-1][w]) % MOD;
      }
    } 
  }
  cout << dp[H][W] << endl;

  return 0;
}
