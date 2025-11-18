#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

// initial
int n, m;
vector<vector<int>> g;
vector<int> dis;
vector<int> par;
const int inf = 1e9;

// helper
void bfs(int src) {
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int nei : g[u]) {
            if (dis[nei] > dis[u] + 1) {
                dis[nei] = dis[u] + 1;
                par[nei] = u;
                q.push(nei);
            }
        }
    }
}
void solve() {
    // input
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1, inf);
    par.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // process
    bfs(1);
    
    // output
    if (dis[n] == inf) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    vector<int> res;
    int cur = n;
    while (cur != 1) {
        res.push_back(cur);
        cur = par[cur];
    }
    res.push_back(1);
    cout << dis[n] + 1 << nl;
    reverse(res.begin(), res.end());
    for (int r : res) {
        cout << r << " ";
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