#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
const ll mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }

    ll full = (1 << n);
    vector<vector<ll>> dp(full, vector<ll>(n, 0));
    dp[1 << 0][0] = 1;

    for (ll mask = 0; mask < full; mask++) {
        for (ll u = 0; u < n; u++) {
            if (!(mask & (1 << u)))
                continue;
            ll ways = dp[mask][u];
            if (!ways)
                continue;

            for (ll v : g[u]) {
                if ((mask & (1 << v)))
                    continue;
                ll newMask = mask | (1 << v);
                dp[newMask][v] = (dp[newMask][v] + ways) % mod;
            }
        }
    }

    cout << dp[full - 1][n - 1] % mod << endl;

    return 0;
}