#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

// inital
int n, m;
vector<vector<int>> g;
vector<bool> vis;
vector<int> par;
vector<int> path;
bool has_cycle = false;

// helper
void dfs(int src, int p) {
    vis[src] = 1;
    par[src] = p;
    for (int nei : g[src]) {
        if (nei == p)
            continue;
        if (!vis[nei]) {
            dfs(nei, src);
        } else {
            int cur = src;
            while (cur != nei) {
                path.push_back(cur);
                cur = par[cur];
            }
            path.push_back(nei);
            path.push_back(src);
            has_cycle = true;
        }
        if (has_cycle)
            return;
    }
}
void solve() {
    // input
    cin >> n >> m;
    g.resize(n + 1);
    par.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // process
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
            if (has_cycle)
                break;
        }
    }

    // output
    if (!has_cycle) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    cout << path.size() << nl;
    for (int p : path) {
        cout << p << " ";
    }
    cout << nl;
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