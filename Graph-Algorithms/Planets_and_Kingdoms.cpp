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
const int maxn = 2e5 + 5;
int n, m;
vector<int> g[maxn], rev_g[maxn];
int visited[maxn];
int cur_scc = 0;
int scc_number[maxn];
vector<int> tout_order;

void dfs1(int u) {
    visited[u] = 1;
    for (int v : g[u])
        if (!visited[v])
            dfs1(v);
    tout_order.push_back(u);
}

void dfs2(int u) {
    visited[u] = 1;
    scc_number[u] = cur_scc;
    for (int v : rev_g[u])
        if (!visited[v])
            dfs2(v);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        if (!visited[u])
            dfs1(u);
    }

    reverse(all(tout_order));
    fill(visited, visited + n + 1, 0);

    for (int u : tout_order) {
        if (!visited[u]) {
            cur_scc++;
            dfs2(u);
        }
    }

    cout << cur_scc << endl;
    for (int u = 1; u <= n; u++) {
        cout << scc_number[u] << " ";
    }
    return 0;
}