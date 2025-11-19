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
map<int, int> g[maxn];
int n;
int degree[maxn];
vector<int> circuit;

void heirholze(int u) {
    while (!g[u].empty()) {
        auto it = g[u].begin();
        int v = it->first;

        g[u][v]--;
        if (g[u][v] == 0)
            g[u].erase(v);

        heirholze(v);
    }
    circuit.push_back(u);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << "10\n";
        exit(0);
    }
    
    int totalNodes = 1 << (n - 1);

    for (int i = 0; i < totalNodes; i++) {
        int u = (i << 1) & (totalNodes - 1);
        g[i][u]++;
        int v = ((i << 1) | 1) & (totalNodes - 1);
        g[i][v]++;
        degree[i]++;
        degree[v]++;
        degree[i]++;
        degree[u]++;
    }

    heirholze(0);

    string result(n - 1, '0');
    for (int i = circuit.size() - 2; i >= 0; i--) {
        result += char('0' + (circuit[i] & 1));
    }
    cout << result << endl;

    return 0;
}