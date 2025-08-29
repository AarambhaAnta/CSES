#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x, n;
    cin >> x >> n;

    set<int> positions;
    multiset<int> lengths;
    positions.insert({0, x});
    lengths.insert(x);

    int points;
    for (int i = 0; i < n; i++) {
        cin >> points;
        positions.insert(points);
        auto it = positions.find(points);
        int preVal = *prev(it);
        int nexVal = *next(it);
        lengths.erase(lengths.find(nexVal - preVal));
        lengths.insert(points - preVal);
        lengths.insert(nexVal - points);
        cout << *lengths.rbegin() << " ";
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