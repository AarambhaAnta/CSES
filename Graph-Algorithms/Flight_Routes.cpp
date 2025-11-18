#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using rev_pq = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    vector<int> dis(k + 1);
    vector<int> vis(n + 1);
    rev_pq<pair<int, int>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u] >= k)
            continue;
        if (u == n) {
            dis[vis[u]] = d;
        }
        ++vis[u];
        for (auto [w, v] : adj[u]) {
            pq.push({d + w, v});
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}