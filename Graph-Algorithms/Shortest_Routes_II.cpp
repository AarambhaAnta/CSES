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
typedef pair<ll, ll> pll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m >> q;

    ll inf = 1e18;
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, inf));

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    for (ll i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (dis[i][k] != inf && dis[k][j] != inf) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    while (q--) {
        ll u, v;
        cin >> u >> v;
        ll d = dis[u][v];
        if (d == inf || d < 0) {
            cout << -1 << '\n';
        } else {
            cout << d << '\n';
        }
    }
    return 0;
}