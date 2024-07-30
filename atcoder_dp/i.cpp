#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define ld long double

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int N;
  cin >> N;
  int H = N / 2 + 1; // floor(N/2)
  
  vector<vector<ld>> prob(N+1, vector<ld>(N+1, 0.0));
  for (int i = 0; i <= N; i++) prob[i][0] = 1.0;

  vector<ld> p(N+1);
  for (int i = 1; i <= N; i++) {
    cin >> p[i];

    prob[i][0] = prob[i-1][0] * (1 - p[i]);
    for (int j = 1; j <= i; j++) {
      prob[i][j] = p[i] * prob[i-1][j-1] + (1 - p[i]) * prob[i-1][j];
    }
    // probability of 1 head after i flips = probability 0 heads after i-1 flips * p(head) + 1 head after i-1 flips * p(tail)
    // prob[i][1] = p[i] * prob[i-1][0];
  }
  ld sum = 0.0;
  for (int i = H; i <= N; i++) {
    sum += prob[N][i];
  }
  cout << fixed << setprecision(10) << sum << endl;

  return 0;
}

