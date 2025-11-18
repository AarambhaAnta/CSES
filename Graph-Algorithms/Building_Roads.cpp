#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

// initial
int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<vector<int>> components;
int current_comp = 0;
// helper
void dfs(int node) {
    components[current_comp].push_back(node);
    vis[node] = true;
    for (int nei : adj[node]) {
        if (!vis[nei]) {
            dfs(nei);
        }
    }
}

void solve() {
    // input
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, false);
    components.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // process
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            current_comp++;
            dfs(i);
        }
    }

    // output
    cout << current_comp - 1 << nl;
    int pre = -1;
    for (int i = 1; i <= n; i++) {
        if (!components[i].empty()) {
            if (pre != -1) {
                cout << pre << " " << components[i][0] << nl;
                pre = components[i][0];
            } else {
                pre = components[i][0];
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}