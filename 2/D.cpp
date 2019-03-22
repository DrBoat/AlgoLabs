#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

const long long INF = 1e12;

struct edge {
    long long a, b, cost;
};

int main()
{
  long long n, m, k, s;
  cin >> n >> m >> k >> s;
  s--;
  vector<edge>e;

  for (long long i = 0; i < m; i++) {
    edge tmp;
    cin >> tmp.a >> tmp.b >> tmp.cost;
    tmp.a--;
    tmp.b--;
    e.push_back(tmp);
  }

  if (k == 0) {
    for(long long i = 0; i < n; i++) {
      if (i == s) {
        cout << 0 << endl;
      }
      else {
        cout << -1 << endl;
      }
    }
    return 0;
  }

  vector<vector<long long>> d;
  for (int i = 0; i < k + 1; i++) {
    d.push_back(vector<long long>(n, INF));
  }
  d[0][s] = 0;

  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < m; j++) {
      if (d[i - 1][e[j].a] < INF) {
        d[i][e[j].b] = min(d[i][e[j].b], d[i - 1][e[j].a] + e[j].cost);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (abs(d[k][i]) >= INF) {
      cout << -1 << endl;
    } else {
      cout << d[k][i] << endl;
    }
  }

  return 0;
}
