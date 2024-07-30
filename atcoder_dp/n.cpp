#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int N;
  cin >> N;

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 1e18));
  vector<vector<int>> opt(N + 1, vector<int>(N + 1, N+1));
  vector<ll> a(N + 1, 0);
  vector<ll> p(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    p[i] = a[i];
  }
  for (int i = 1; i <= N; i++) {
    p[i] += p[i - 1];
    opt[i][i] = i;
    dp[i][i] = 0;
  }

  // compute dp[i,j] using dp[i,j-1] and dp[i+1,j]
  for (int i = N - 1; i >= 1; i--) {
    for (int j = i + 1; j <= N; j++) {
      ll nm = 1e18;
      ll cost = (p[j] - p[i - 1]);

      for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
        // cout << i << " " << k << " " << j << " " << nm << " " << (p[j] - p[i-1]) << endl;
        if (dp[i][k] + dp[k+1][j] + cost <= nm) {
          opt[i][j] = k;
          nm = dp[i][k] + dp[k+1][j] + cost;
        }
      }
      dp[i][j] = nm;
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }
  cout << dp[1][N] << endl;

  return 0;
}
