#include <iostream>
#include <vector>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
const int MAXN = 1e5+1;
vector<vector<int>> a(MAXN, vector<int>());
int visited[MAXN];
ll dp[MAXN][2];

void dfs(int n) {
  if (visited[n]) return;
  visited[n] = true;
  
  ll white = 1;
  ll black = 1;

  for (auto nbr : a[n]) {
    if (!visited[nbr]) {
      dfs(nbr);
      white = (white * ((dp[nbr][0] + dp[nbr][1]) % MOD) % MOD);
      black = (black * (dp[nbr][0])) % MOD;
    }
  }

  dp[n][0] = (dp[n][0] + white) % MOD;
  dp[n][1] = (dp[n][1] + black) % MOD;
  // cout << n << " " << dp[n][0] << " " << dp[n][1] << endl;

  return;
}

int main() {
  int N;
  cin >> N;

  int x, y;
  for (int i = 0; i < N-1; i++) {
    cin >> x >> y;
    a[x-1].push_back(y-1);
    a[y-1].push_back(x-1);
  }
  
  dfs(0);
  cout << (dp[0][0] + dp[0][1]) % MOD << endl;

  return 0;
}
