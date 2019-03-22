#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <set>

using namespace std;

const long long INF = 1e18;

int main()
{
  freopen("dwarf.in", "r", stdin);
  freopen("dwarf.out", "w", stdout);
  long long n, m;
  cin >> n >> m;
  vector<long long> c(n);
  
  for (long long i = 0; i < n; i++)
  {
    cin >> c[i];
  }
  vector<vector<pair<long long, long long>>> g(n);
  for (long long i = 0; i < m; i++)
  {
    long long tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    tmp1--;
    tmp2--;
    tmp3--;
    g[tmp2].push_back(make_pair(tmp3, tmp1));
    g[tmp3].push_back(make_pair(tmp2, tmp1));
  }

  set<pair<long long, long long>> d;
  for (long long i = 0; i < n; i++) {
    d.insert(make_pair(c[i], i));
  }

  while (true) {
      long long i = d.begin() -> second;
      d.erase(d.begin());

      for (auto x : g[i])
      {
        long long fst = c[i] + c[x.first];
        if (fst < c[x.second])
        {
          d.erase(make_pair(c[x.second], x.second));
          c[x.second] = fst;
          d.insert(make_pair(c[x.second], x.second));
        }
      }
      if (d.empty()) break;
    }


    long long ans = c[0];

    cout << ans << endl;
    
    return 0;
}
