#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ump[x]++;
    }

    int ans = 1;
    for (auto p : ump) {
        ans = (ans * (p.second + 1)) % MOD;
    }
    cout << ans - 1 << '\n';
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