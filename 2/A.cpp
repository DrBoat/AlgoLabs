#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

const int maxn = 101;
long long n;
int dist[maxn][maxn];

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> dist[i][j];
    }
  }
  for (int k = 1; k <= n; k++)
  {
    for (int i = 0; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << dist[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
