#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

// inital
int n, m;
vector<vector<int>> g;
bool is_bipartite = true;
vector<int> colors;

// helper
void dfs(int src, int c) {
    colors[src] = c;
    for (int nei : g[src]) {
        if (colors[nei] == 0) {
            dfs(nei, 3 - c);
        } else if (colors[nei] == c) {
            is_bipartite = false;
            return;
        }
    }
}
void solve() {
    // input
    cin >> n >> m;
    g.resize(n + 1);
    colors.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // process
    for (int i = 1; i <= n; i++){
        if(colors[i]==0){
            dfs(i, 1);
        }
    }

    // output
    if (!is_bipartite) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
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