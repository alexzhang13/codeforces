#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 1e5;
const int MAXM = 1e5;

int dp[MAXN];
vector<vector<int>> edges(MAXN);

template<typename T>
bool ckmax(T& a, T&b) {
  return a < b ? a = b, 1 : a;
}

int topo(int v) {
  if (dp[v] != 0) return dp[v];

  for (int i = 0; i < edges[v].size(); i++) {
    dp[edges[v][i]] = topo(edges[v][i]);
    dp[v] = max(dp[v], dp[edges[v][i]] + 1);
  } 

  return dp[v];
}

int main() {

  int n, m;
  cin >> n >> m;

  // vector<pair<int, int>> edges;
  
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    edges[x-1].push_back(y-1);
  }

  for (int i = 0; i < n; i++) {
    topo(i);
  }

  int mx = 0;
  for (int i = 0; i < n; i++) {
    ckmax(mx, dp[i]);
  }
  cout << mx << endl;

  return 0;
}
