#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

const int INF = 1e9;

const int maxn = 101;
int dist[maxn][maxn];

int main()
{
  long long n, m, s = 0;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);

  for (int i = 0; i < m; i++) {
    int tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    g[tmp1 - 1].push_back(make_pair(tmp2 - 1, tmp3));
    g[tmp2 - 1].push_back(make_pair(tmp1 - 1, tmp3));
  }
  
  vector<int> d(n, INF),  p(n);
  d[s] = 0;

  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, s));

  while (!q.empty()) {
    int v = q.top().second;
    int cur_d = -q.top().first;
    q.pop();
    if (cur_d > d[v])  continue;
 
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first;
      int len = g[v][i].second;

      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
        q.push(make_pair(-d[to], to));
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << d[i] << ' ';
  }
  return 0;
}