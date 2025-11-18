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
set<int> g[maxn];
vector<int> circuit;

void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void find_cycle(int u) {
    while (!g[u].empty()) {
        int v = *g[u].begin();
        g[u].erase(v);
        g[v].erase(u);
        find_cycle(v);
    }
    circuit.push_back(u);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2 != 0)
            fail();
    }

    find_cycle(1);

    if (circuit.size() != m + 1)
        fail();

    for (int p : circuit) {
        cout << p << " ";
    }

    return 0;
}