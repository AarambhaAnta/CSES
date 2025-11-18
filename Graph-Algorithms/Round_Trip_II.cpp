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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> path;
    vector<int> visited(n + 1), parent(n + 1);
    function<void(int, int)> dfs = [&](int src, int par) {
        visited[src] = 1;
        parent[src] = par;
        for (int v : adj[src]) {
            if (visited[v] == 0) {
                dfs(v, src);
            } else if (visited[v] == 1) {
                if (path.empty()) {
                    for (int at = src;; at = parent[at]) {
                        path.push_back(at);
                        if (at == v)
                            break;
                    }
                    path.push_back(src);
                    reverse(all(path));
                }
            }
        }
        visited[src] = 2;
    };

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, 0);
        }
    }
    if (!path.size()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << path.size() << endl;
    for (int p : path) {
        cout << p << " ";
    }

    return 0;
}