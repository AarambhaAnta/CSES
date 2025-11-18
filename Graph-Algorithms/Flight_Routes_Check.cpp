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
int n, m;
const int maxn = 2e5 + 5;
int visited1[maxn], visited2[maxn];
vector<int> g[maxn], revG[maxn];

void dfs1(int u) {
    visited1[u] = 1;
    for (int v : g[u])
        if (!visited1[v])
            dfs1(v);
}

void dfs2(int u) {
    visited2[u] = 1;
    for (int v : revG[u])
        if (!visited2[v])
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
        revG[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);

    for (int u = 1; u <= n; u++) {
        if (!visited1[u]) {
            cout << "NO\n";
            cout << 1 << " " << u << endl;
            return 0;
        }
        if (!visited2[u]) {
            cout << "NO\n";
            cout << u << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}