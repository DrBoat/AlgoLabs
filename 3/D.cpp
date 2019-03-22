#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string p, t;
  cin >> p >> t;
  string s = p + "\\" + t;

  int n = s.size(), np = p.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for(int i = 1; i < n; i++) {
    if(i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if(i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  vector<int> ans;
  for (int i = np + 1; i < n; i++) {
    if (z[i] == np) {
      ans.push_back(i - np);
    }
  }

  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}