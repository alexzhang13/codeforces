#include <iostream>
#include <vector>

using namespace std;

const int K = 1e5 + 1;
int dp[K];

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  
  vector<int> a;
  int N, K;
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    dp[a[i]] = 1;
  }

  return 0;
}
