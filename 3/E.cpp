#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  char c;
  vector<char> s;
  while (cin >> c) {
    s.push_back(c);
  }

  int n = s.size();
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

  for (int i = 0; i < n; i++) {
    if (i + z[i] == n && n % i == 0) {
      cout << i;
      return 0;
    }
  }
  cout << n;
  return 0;
}