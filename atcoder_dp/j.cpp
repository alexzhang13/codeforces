#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

long double dp[301][301][301];

long double compute_dp(int n, int x, int y, int z) {
  if (x < 0 || y < 0 || z < 0) return 0;
  if (x == 0 && y == 0 && z == 0) return 0;
  if (dp[x][y][z] != 0) return dp[x][y][z];

  long double res = n + x * compute_dp(n, x-1, y, z) + y * compute_dp(n, x+1, y-1, z) + z * compute_dp(n, x, y+1, z-1);
  dp[x][y][z] = res / (x + y + z);
  
  return dp[x][y][z];
}

int main() {
  int N;
  cin >> N;
  vector<int> p(N);

  long double prob = 0;
  int t = 0;
  // coupon collector problem
  vector<int> cnt(4, 0);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    cnt[p[i]]++;
    t += p[i];
  }

  prob = compute_dp(N, cnt[1], cnt[2], cnt[3]);

  cout << fixed << setprecision(10) << prob << endl;
  return 0;
}
