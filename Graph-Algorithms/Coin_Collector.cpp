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
vector<ll> g[maxn], rev_g[maxn];
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

ll cur_scc = 0;
ll scc_number[maxn];
void dfs2(ll u) {
    visited[u] = 1;
    scc_number[u] = cur_scc;
    for (ll v : rev_g[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

set<ll> condensed_graph[maxn];
ll condensed_coins[maxn];
ll dp[maxn];

void dfs3(ll u) {
    visited[u] = 1;
    for (ll v : condensed_graph[u]) {
        if (!visited[v]) {
            dfs3(v);
        }
    }
    tout_order.push_back(u);
}

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
        rev_g[v].push_back(u);
    }

    for (ll u = 1; u <= n; u++) {
        if (!visited[u])
            dfs1(u);
    }
    reverse(all(tout_order));
    fill(visited, visited + n + 1, 0);

    for (ll u : tout_order) {
        if (!visited[u]) {
            cur_scc++;
            dfs2(u);
        }
    }

    for (ll u = 1; u <= n; u++) {
        for (ll v : g[u]) {
            if (scc_number[u] != scc_number[v]) {
                condensed_graph[scc_number[u]].insert(scc_number[v]);
            }
        }
        condensed_coins[scc_number[u]] += coins[u];
    }

    fill(visited, visited + n + 1, 0);
    tout_order.clear();

    for (ll u = 1; u <= cur_scc; u++) {
        if (!visited[u]) {
            dfs3(u);
        }
    }
    reverse(all(tout_order));

    // for (ll u : tout_order) {
    //     cout << u << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for (ll i = 1; i <= cur_scc; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}