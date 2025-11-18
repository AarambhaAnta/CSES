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
    ll inf = 1e18;
    vector<tuple<ll, ll, ll>> edges;
    vector<vector<ll>> g(n + 1), rev_g(n + 1);
    vector<ll> dis(n + 1, inf);

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, -w});
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    const size_t nn = n;
    function<vector<bool>(ll, vector<vector<ll>>)> bfs = [&](ll src, vector<vector<ll>> graph) {
        vector<bool> can_reach(nn + 1, false);
        can_reach[src] = true;
        queue<ll> q;
        q.push(src);
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            for (ll v : graph[u]) {
                if (!can_reach[v]) {
                    can_reach[v] = true;
                    q.push(v);
                }
            }
        }
        return can_reach;
    };
    vector<bool> can_reach = bfs(1, g);
    vector<bool> can_reach_from_n = bfs(n, rev_g);
    for (size_t i = 0; i <= nn; i++) {
        can_reach[i] = can_reach[i] && can_reach_from_n[i];
    }

    dis[1] = 0;

    for (ll i = 1; i <= n; i++) {
        for (auto [u, v, w] : edges) {
            if (!can_reach[u] || !can_reach[v])
                continue;
            ll new_dis = min(dis[v], dis[u] + w);
            if (i == n && new_dis < dis[v]) {
                cout << -1 << endl;
                return 0;
            }
            dis[v] = new_dis;
        }
    }

    cout << -dis[n] << endl;
    return 0;
}