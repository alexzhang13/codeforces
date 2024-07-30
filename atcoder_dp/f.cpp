#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXL = 3000;

struct S {
  char c;
  int prev_i=-1;
  int prev_j=-1;
  int len=0;
};

S dp[MAXL+1][MAXL+1];

S S_max(const S& a, const S&b) {
  if (a.len >= b.len) {
    return S{a};
  }
  return S{b};
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  std::string s, t;
  cin >> s >> t;

  int sl = s.length();
  int tl = t.length();

  for (int i = 1; i <= sl; i++) {
    for (int j = 1; j <= tl; j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = {t[j-1], i-1, j-1, dp[i-1][j-1].len + 1};
      } else {
        dp[i][j] = S_max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  vector<char> out;
  int curr_i = sl;
  int curr_j = tl;
  int prev_i = dp[sl][tl].prev_i; 
  int prev_j = dp[sl][tl].prev_j;
  char c;
  while (prev_i != -1) {
    c = dp[curr_i][curr_j].c;
    out.push_back(c);

    int tmpi = prev_i;
    int tmpj = prev_j;
    prev_i = dp[tmpi][tmpj].prev_i;
    prev_j = dp[tmpi][tmpj].prev_j;
    curr_i = tmpi;
    curr_j = tmpj;
  }

  for (int i = out.size() - 1; i >= 0; i--) {
    cout << out[i];
  }
  
  cout << endl;

  return 0;
}

