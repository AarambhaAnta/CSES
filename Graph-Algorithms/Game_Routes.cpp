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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll mod = 1e9 + 7;
    vector<ll> dp(n + 1);
    function<ll(ll)> dfs = [&](ll u) -> ll {
        if (u == n)
            return 1;
        if (dp[u] != -1)
            return dp[u];
        dp[u] = 0;
        for (ll v : adj[u]) {
            dp[u] = (dp[u] + dfs(v)) % mod;
        }
        return dp[u];
    };

    dfs(1);
    cout << dp[1] << endl;
    return 0;
}