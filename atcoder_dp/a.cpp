#include <iostream>

using namespace std;

const int MAXN = 1e5;
int h[MAXN];
int dp[MAXN];

int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  for (int i = 1; i < N; i++) {
    if (i - 2 >= 0) {
      dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                  dp[i - 2] + abs(h[i] - h[i - 2]));
    } else {
      dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    }
  }
  cout << dp[N - 1] << endl;
  return 0;
}

// dp[i] = max(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
