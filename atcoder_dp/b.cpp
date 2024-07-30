#include <iostream>

using namespace std;

const int MAXN = 1e5;
int h[MAXN];
int dp[MAXN];

int main(int argc, char *argv[]) {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  int m = 0;
  for (int i = 1; i < N; i++) {
    m = dp[i - 1] + abs(h[i] - h[i - 1]);
    for (int k = 2; k <= K && (i - k >= 0); k++) {
      m = min(m, dp[i - k] + abs(h[i] - h[i - k]));
    }
    dp[i] = m;
    // cout << m << " ";
  }
  // cout << endl;
  cout << dp[N - 1] << endl;
  return 0;
}

// dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
