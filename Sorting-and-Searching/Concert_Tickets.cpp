#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> max_price(m);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> max_price[i];
    }

    for (int i = 0; i < m; i++) {
        int mp = max_price[i];
        auto it = tickets.upper_bound(mp);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
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