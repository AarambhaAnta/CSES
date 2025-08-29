#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> values(n + 1), positionOf(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        positionOf[values[i]] = i;
    }
    int inverstion = 1;
    for (int i = 2; i <= n; i++) {
        inverstion += (positionOf[i] < positionOf[i - 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        set<pair<int, int>> st;
        if (values[l] + 1 <= n) {
            st.insert({values[l], values[l] + 1});
        }
        if (values[l] - 1 > 0) {
            st.insert({values[l] - 1, values[l]});
        }
        if (values[r] + 1 <= n) {
            st.insert({values[r], values[r] + 1});
        }
        if (values[r] - 1 > 0) {
            st.insert({values[r] - 1, values[r]});
        }

        for (auto p : st) {
            inverstion -= (positionOf[p.second] < positionOf[p.first]);
        }
        swap(values[l], values[r]);
        positionOf[values[l]] = l;
        positionOf[values[r]] = r;
        for (auto p : st) {
            inverstion += (positionOf[p.second] < positionOf[p.first]);
        }
        cout << inverstion << '\n';
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