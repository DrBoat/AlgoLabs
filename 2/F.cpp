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
    long long n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> g(n);
    

    for (long long i = 0; i < m; i++) {
        long long tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp1--;
        tmp2--;
        g[tmp1].push_back(make_pair(tmp2, tmp3));
        g[tmp2].push_back(make_pair(tmp1, tmp3));
    }

    cin >> a >> b >> c;
    a--;
    b--;
    c--;
    
    vector<long long> da(n, INF), db(n, INF);
    da[a] = 0;
    db[b] = 0;
    
    set<pair<long long, long long>> d;
    d.insert(make_pair(0, a));
    while (true) {
        long long i = d.begin() -> second;
        da[i] = d.begin() -> first;
        d.erase(d.begin());

        for (auto & x : g[i]) {
            if (da[x.first] > da[i] + x.second) {
                d.erase(make_pair(da[x.first], x.first));
                da[x.first] = da[i] + x.second;
                d.insert(make_pair(da[x.first], x.first));
            }
        }
        if (d.empty()) break;
    }

    d.insert(make_pair(0, b));
    while (true) {
        long long i = d.begin() -> second;
        db[i] = d.begin() -> first;
        d.erase(d.begin());

        for (auto & x : g[i]) {
            if (db[x.first] > db[i] + x.second) {
                d.erase(make_pair(db[x.first], x.first));
                db[x.first] = db[i] + x.second;
                d.insert(make_pair(db[x.first], x.first));
            }
        }
        if (d.empty()) break;
    }

    long long ans = min(min(INF, da[b] + db[c]),
                        min(da[b] + da[c], db[c] + da[c]));

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
