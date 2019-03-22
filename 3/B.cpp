#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> pref(n);
  for (int i = 1; i < n; i++) {
    int j = pref[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pref[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    pref[i] = j;
  }

  for (auto i : pref)
  {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}