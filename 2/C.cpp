#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, m = 0;
const int inf = 1e9, maxe = 10000;
struct edge
{
  int a, b, cost;
};

edge e[maxe];

void negc()
{
  vector <int> d(n, inf);
  vector <int> p(n, -1);
  d[0] = 0;
  int x;
  for (int i = 0; i < n; i++)
  {
    x = -1;
    for (int j = 0; j < m; j++)
    {
      if (d[e[j].b] > d[e[j].a] + e[j].cost)
      {
        d[e[j].b] = d[e[j].a] + e[j].cost;
        p[e[j].b] = e[j].a;
        x = e[j].b;
      }
    }
  }
  if (x == -1)
  {
    printf("NO");
  }
  else
  {
    int y = x;
    for (int i = 0; i < n; i++)
    {
      y = p[y];
    }
    vector <int> path;
    for (int cur = y; true; cur = p[cur])
    {
      if (cur == y && path.size() > 1)
      {
        break;
      }
      path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    printf("YES\n%d\n", path.size());
    for (int i = 0; i < path.size(); i++)
    {
      printf("%d ", path[i] + 1);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (tmp != 100000)
      {
        e[m].a = i;
        e[m].b = j;
        e[m++].cost = tmp;
      }
    }
  }
  negc();
  return 0;
}
