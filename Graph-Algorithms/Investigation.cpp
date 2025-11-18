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
    vector<vector<pll>> g(n + 1), rev_g(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        rev_g[v].push_back({w, u});
    }

    ll inf = 1e18;
    ll mod = 1e9 + 7;
    vector<ll> prices(n + 1, inf);
    vector<bool> visited(n + 1, false);
    vector<ll> n_min_prices(n + 1), min_flights(n + 1), max_flights(n + 1);

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    prices[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (prices[u] < d)
            continue;
        for (auto [w, v] : rev_g[u]) {
            ll new_price = prices[u] + w;
            if (new_price < prices[v]) {
                prices[v] = new_price;
                pq.push({new_price, v});
            }
        }
    }

    function<void(ll)> dfs = [&](ll u)->void {
        if (visited[u])
            return;
        visited[u] = true;
        if (u == n) {
            n_min_prices[u] = 1;
            min_flights[u] = 0;
            max_flights[u] = 0;
            return;
        }
        n_min_prices[u] = 0;
        min_flights[u] = inf;
        max_flights[u] = -inf;
        for (auto [w, v] : g[u]) {
            if (prices[u] == prices[v] + w) {
                dfs(v);
                n_min_prices[u] = (n_min_prices[u] + n_min_prices[v]) % mod;
                min_flights[u] = min(min_flights[u], min_flights[v] + 1);
                max_flights[u] = max(max_flights[u], max_flights[v] + 1);
            }
        }
    };

    dfs(1);

    cout << prices[1] << " " << n_min_prices[1] << " " << min_flights[1] << " " << max_flights[1]
         << endl;

    return 0;
}