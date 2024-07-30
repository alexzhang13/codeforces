#include <iostream>

using namespace std;

const int MAXN = 1e5;

int v[3][MAXN + 1];

int main(int argc, char *argv[]) {
  int N;
  cin >> N;

  int a, b, c;
  int u1, u2, u3;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;

    u1 = max(v[1][i] + a, v[2][i] + a);
    u2 = max(v[0][i] + b, v[2][i] + b);
    u3 = max(v[0][i] + c, v[1][i] + c);

    v[0][i + 1] = u1;
    v[1][i + 1] = u2;
    v[2][i + 1] = u3;

    // cout << v[0][i + 1] << " " << v[1][i + 1] << " " << v[2][i + 1] << endl;
  }

  int res = max(max(v[0][N], v[1][N]), v[2][N]);
  cout << res << endl;

  return 0;
}
