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

    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(2 * n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[u + n].push_back({w, v + n});
        adj[u].push_back({w / 2, v + n});
    }

    ll inf = 1e18;
    vector<ll> dis(2 * n + 1, inf);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] < d)
            continue;
        for (auto [w, v] : adj[u]) {
            ll new_dis = dis[u] + w;
            if (new_dis < dis[v]) {
                dis[v] = new_dis;
                pq.push({new_dis, v});
            }
        }
    }
    cout << min(dis[n], dis[2 * n]) << endl;
    return 0;
}