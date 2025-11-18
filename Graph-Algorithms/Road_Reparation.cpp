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

ll parent[maxn], d_rank[maxn];
ll set_size = 0;

void make_set(ll v) {
    parent[v] = v;
    d_rank[v] = 1;
}

ll find_set(ll x) {
    if (x != parent[x])
        return parent[x] = find_set(parent[x]);
    return x;
}

void merge(ll a, ll b) {
    a = find_set(a), b = find_set(b);
    if (a != b) {
        if (d_rank[a] >= d_rank[b]) {
            parent[b] = a;
            d_rank[a] += d_rank[b];
        } else {
            parent[a] = b;
            d_rank[b] += d_rank[a];
        }
        set_size--;
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    set_size = n;
    vector<tuple<ll, ll, ll>> edges;  // w, u, v;
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(all(edges));

    for (ll i = 1; i <= n; i++) {
        make_set(i);
    }

    ll min_cost = 0;
    ll no_roads = 0;
    for (auto [w, u, v] : edges) {
        if (find_set(u) != find_set(v)) {
            min_cost += w;
            no_roads++;
            merge(u, v);
            if (no_roads == n - 1)
                break;
        }
    }

    if (no_roads < n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << min_cost << "\n";
    }

    return 0;
}