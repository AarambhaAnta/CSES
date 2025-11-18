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
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<ll> dis(n + 1);
    vector<ll> parent(n + 1);
    optional<int> path_end;

    for (ll i = 1; i <= n; i++) {
        for (auto [u, v, w] : edges) {
            ll new_dis = dis[u] + w;
            if (new_dis < dis[v]) {
                dis[v] = new_dis;
                parent[v] = u;
                if (i == n) {
                    path_end = v;
                }
            }
        }
    }

    if (!path_end) {
        cout << "NO" << endl;
        return 0;
    }

    vector<bool> vis(n + 1, false);
    vector<int> res;
    for (int v = *path_end;; v = parent[v]) {
        res.push_back(v);
        if (vis[v])
            break;
        vis[v] = true;
    }
    reverse(all(res));
    cout << "YES" << endl;
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " ";
        if (i > 0 && res[i] == res.front())
            break;
    }

    cout << endl;

    return 0;
}