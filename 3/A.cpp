#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

const long long alphabet = 256, maxlen = 1e5;


string s;
long long n;

vector<long long> p(maxlen), cnt(maxlen);
vector<vector<long long>> c;

bool compare(long long i, long long j, long long l, long long k) {
  pair<long long, long long> a = make_pair(c[k][i], c[k][i + l - (1<<k)]);
  pair<long long, long long> b = make_pair(c[k][j], c[k][j + l - (1<<k)]);
  if (a == b) {
    return true;
  }
  return false;
}

int main() {
  cin >> s;
  n = s.size();
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

  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    long long tmp1, tmp2, tmp3, tmp4;
    cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
    int l = tmp4 - tmp3;
    if (tmp2 - tmp1 == l) {
      int t = 1, k = 0;
      l++;
      while (t * 2 <= l) {
        t *= 2;
        k++;
      }
      if (compare((tmp1 - 1), (tmp3 - 1), l, k)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}