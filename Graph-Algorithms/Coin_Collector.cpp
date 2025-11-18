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
const ll maxn = 2e5 + 5;
ll n, m;
vector<ll> g[maxn], gRev[maxn];
ll coins[maxn];
ll visited[maxn];
vector<ll> tout_order;

void dfs1(ll u) {
    visited[u] = 1;
    for (ll v : g[u]) {
        if (!visited[v])
            dfs1(v);
    }
    tout_order.push_back(u);
}

ll curScc = 0;
ll scc[maxn];
void dfs2(ll u) {
    visited[u] = 1;
    scc[u] = curScc;
    for (ll v : gRev[u]) {
        if (!visited[v])
            dfs2(v);
    }
}

ll coinsCondense[maxn];
ll dp[maxn];
vector<ll> gCondense[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gRev[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if (!visited[i])
            dfs1(i);
    }

    reverse(all(tout_order));
    fill(visited, visited + n + 1, 0);

    for (ll v : tout_order) {
        if (!visited[v]) {
            curScc++;
            dfs2(v);
        }
    }


    for (ll u = 1; u <= n; u++) {
        coinsCondense[scc[u]] += coins[u];
        for (ll v : g[u]) {
            if (scc[u] != scc[v]) {
                gCondense[scc[u]].push_back(scc[v]);
            }
        }
    }

    vector<ll> scc_topo;

    for (ll node : tout_order) {
        ll s = scc[node];
        if (scc_topo.empty() || scc_topo.back() != s) {
            scc_topo.push_back(s);
        }
    }

    for (ll i = scc_topo.size() - 1; i >= 0; i--) {
        ll u = scc_topo[i];
        dp[u] = coinsCondense[u];
        for (ll v : gCondense[u]) {
            dp[u] = max(dp[u], coinsCondense[u] + dp[v]);
        }
    }

    ll maxCoins = *max_element(dp, dp + curScc + 1);
    cout << maxCoins << '\n';

    return 0;
}