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

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    ll inf = 1e18;
    vector<bool> visited(n + 1, false);
    vector<ll> parent(n + 1), longest(n + 1);
    function<ll(ll)> dfs = [&](ll u) {
        if (visited[u])
            return longest[u];
        visited[u] = true;
        longest[u] = -inf;
        if(u==n)
            return longest[n] = 1;
        for (ll v : g[u]) {
            dfs(v);
            if (longest[v] + 1 > longest[u]) {
                longest[u] = longest[v] + 1;
                parent[u] = v;
            }
        }
        return longest[u];
    };

    if (dfs(1) < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dfs(1) << "\n";
    for (ll at = 1; at != 0; at = parent[at]) {
        cout << at << " ";
    }
    return 0;
}