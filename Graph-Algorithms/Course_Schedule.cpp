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
    vector<int> indeg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    vector<int> no_incoming;
    for (int u = 1; u <= n; u++) {
        if (indeg[u] == 0) {
            no_incoming.push_back(u);
        }
    }

    for (int i = 0; i < no_incoming.size(); i++) {
        int u = no_incoming[i];
        for (int v : adj[u]) {
            --indeg[v];
            if (indeg[v] == 0) {
                no_incoming.push_back(v);
            }
        }
    }

    if(no_incoming.size()<n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int x:no_incoming){
        cout << x << " ";
    }

    return 0;
}