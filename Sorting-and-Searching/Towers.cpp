#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    multiset<int> mt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = mt.upper_bound(x);
        if (it != mt.end()) {
            mt.erase(it);
        }
        mt.insert(x);
    }
    cout << mt.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}