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
typedef pair<ll, ll> pii;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    ll inf = 1e18;
    vector<ll> dis(n + 1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;

        for (auto [weight, v] : adj[u]) {
            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }

    return 0;
}