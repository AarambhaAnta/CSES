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

map<int, int> g[maxn];
int inDeg[maxn], outDeg[maxn];
vector<int> circuit;

void esc() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void hierholzer(int u) {
    while (!g[u].empty()) {
        auto it = g[u].begin();
        int v = it->first;

        g[u][v]--;
        if (g[u][v] == 0)
            g[u].erase(v);

        hierholzer(v);
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
        g[u][v]++;
        outDeg[u]++;
        inDeg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (outDeg[i] - inDeg[i] != 1 && outDeg[i] - inDeg[i] != 0) {
                esc();
            }
        } else if (i == n) {
            if (outDeg[1] - inDeg[1] == 0) {
                if (inDeg[i] - outDeg[i] != 0) {
                    esc();
                }
            } else {
                if (inDeg[i] - outDeg[i] != 1) {
                    esc();
                }
            }
        } else if (inDeg[i] != outDeg[i]) {
            esc();
        }
    }

    hierholzer(1);

    if (circuit.size() != m + 1) {
        esc();
    }

    if (circuit.front() != n) {
        esc();
    }

    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i] << " ";
    }


    return 0;
}