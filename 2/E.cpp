#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

struct edge {
  long long a, b, cost;
};

const long long INF = 8000000000000000000;

long long n, m, v;
vector<edge> e;

vector<vector<long long>> g;
vector<bool> used, used2;

void dfs(long long u) {
  if (used[u]) return;
  used[u] = true;
  for (long long i = 0; i < g[u].size(); i++) {
    if (used[g[u][i]] == 0) dfs(g[u][i]);
  }
}

void dfs2(long long u) {
  if (used2[u]) return;
  used2[u] = true;
  for (long long i = 0; i < g[u].size(); i++) {
    if (used2[g[u][i]] == 0) dfs2(g[u][i]);
  }
}

void solve() {
  vector<long long> d(n, INF);
  d[v] = 0;

  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (used2[e[j].b] && d[e[j].a] < INF && d[e[j].b] > d[e[j].a] + e[j].cost)
      {
          d[e[j].b] = d[e[j].a] + e[j].cost;
          if (d[e[j].b] < -INF)
          {
              d[e[j].b] = -INF;
          }
      }
    }
  }

  vector<long long> ld = d;

  for (long long i = 0; i < m; i++)
  {
      if (used2[e[i].b] && ld[e[i].a] < INF && ld[e[i].b] > ld[e[i].a] + e[i].cost)
      {
          ld[e[i].b] = ld[e[i].a] + e[i].cost;
      }
  }

  for (long long i = 0; i < n; i++)
  {
      if (used2[i] && ld[i] != d[i])
      {
          dfs(i);
      }
  }

  for (long long i = 0; i < n; i++) {
    if (!used2[i]) cout << '*' << endl;
    else if (used[i]) cout << '-' << endl;
    else cout << d[i] << endl;
  }
}


int main()
{
  cin >> n >> m >> v;
  v--;
  g.resize(n);
  used.resize(n);
  used2.resize(n);

  for (long long i = 0; i < m; i++) {
    edge tmp;
    cin >> tmp.a >> tmp.b >> tmp.cost;
    tmp.a--;
    tmp.b--;
    g[tmp.a].push_back(tmp.b);
    e.push_back(tmp);
  }

  dfs2(v);
  solve();
  return 0;
}
