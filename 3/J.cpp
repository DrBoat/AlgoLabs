#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

const long long alphabet = 256, maxlen = 1e5;

string s;
long long n, log_n, maxh;

vector<long long> p(maxlen), cnt(maxlen), l;
vector<vector<long long>> c;

int lcp (int i, int j) {
  int ans = 0;
  for (int k = log_n; k >= 0; --k) {
    if (c[k][i] == c[k][j]) {
      ans += 1 << k;
      i += 1 << k;
      j += 1 << k;
    }
  }
  return ans;
}

int main() {
  freopen("i", "r", stdin);
  freopen("o", "w", stdout);
  cin >> s;
  n = s.size();
  l.resize(n);
  long long tmp = 1;
  while (tmp * 2 <= n) {
    tmp *= 2;
    log_n++;
  }
  c.push_back(vector<long long>(maxlen));

  for (long long i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  for (long long i = 1; i < alphabet; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (long long i = 0; i < n; i++) {
    p[--cnt[s[i]]] = i;
  }
  c[0][p[0]] = 0;
  long long classes = 1;
  for (long long i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) {
      classes++;
    }
    c[0][p[i]] = classes - 1;
  }

  vector<long long> pn(maxlen), cn(maxlen);
  for (long long h = 0; (1 << h) < n; h++) {
    for (long long i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) {
        pn[i] += n;
      }
    }

    cnt.resize(0);
    cnt.resize(maxlen);
    for (long long i = 0; i < n; i++) {
      cnt[c[h][pn[i]]]++;
    }
    for (long long i = 1; i < classes; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (long long i = n - 1; i >= 0; i--) {
      p[--cnt[c[h][pn[i]]]] = pn[i];
    }

    cn[p[0]] = 0;
    classes = 1;
    for (long long i = 1; i < n; i++) {
      long long mid1 = (p[i] + (1<<h)) % n, mid2 = (p[i - 1] + (1<<h)) % n;
      if (c[h][p[i]] != c[h][p[i - 1]] || c[h][mid1] != c[h][mid2]) {
        ++classes;
      }
      cn[p[i]] = classes-1;
    }

    c.push_back(vector<long long>(maxlen));
    for(long long i = 0; i < n; i++)
    {
      c[h + 1][i] = cn[i];
    }
  }

  int k = 0;
  for (int i = 0; i < n; i++) {
    if (k > 0) {
      k--;
    }
    if (p[i] == n - 1) {
      l[n - 1] = -1;
      k = 0;
    } else {
      int j = s[pos[i] + 1]
      while (max(i + k, j + k) < n and str[i + k] == str[j + k]) {
        k++
      }
      lcp[pos[i]] = k
    }
  }

  for (int i = 0; i < n; i++) {
    cout << p[i] + 1 << ' ';
  }
  cout << endl;
  for (int i = 0; i + 1 < n; i++) {
    cout << s[i] << ' ';
  }

  // l.resize(n);
  // for (int i = 0; i + 1 < n; i++) {
  //   l[i] = lcp(i, (i + 1));
  // }

  // long long ans = n - p[0];
  // for (int i = 1; i < n; i++) {
  //   ans += (n - (p[i] + 1) - lcp((i - 1), i));
  // }
  // cout << ans - 3;
  return 0;
}