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
const int maxn = 4e5 + 10;
int n, m;
vector<int> g[maxn], rev_g[maxn];
vector<int> tout_order;
int visited[maxn];

int cur_scc = 0;
int scc_number[maxn];

int negate(int x) {
    return x > m ? x - m : x + m;
}

void add_clause(int x, int y) {
    g[::negate(x)].push_back(y);
    g[::negate(y)].push_back(x);
    rev_g[x].push_back(::negate(y));
    rev_g[y].push_back(::negate(x));
}

void dfs1(int u) {
    visited[u] = 1;
    for (int v : g[u])
        if (!visited[v])
            dfs1(v);
    tout_order.push_back(u);
}

void dfs2(int u) {
    scc_number[u] = cur_scc;
    visited[u] = 1;
    for (int v : rev_g[u])
        if (!visited[v])
            dfs2(v);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char s1, s2;
        int u, v;
        cin >> s1 >> u >> s2 >> v;

        if (s1 == '-')
            u = ::negate(u);
        if (s2 == '-')
            v = ::negate(v);

        add_clause(u, v);
    }

    for (int u = 1; u <= 2 * m; u++) {
        if (!visited[u])
            dfs1(u);
    }

    reverse(all(tout_order));
    fill(visited, visited + 2 * m + 5, 0);

    for (int u : tout_order) {
        if (!visited[u]) {
            cur_scc++;
            dfs2(u);
        }
    }

    vector<bool> assignment(m + 1);
    for (int u = 1; u <= m; u++) {
        if (scc_number[u] == scc_number[::negate(u)]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        assignment[u] = scc_number[u] > scc_number[::negate(u)];
    }

    for (int i = 1; i <= m; i++) {
        cout << (assignment[i] ? '+' : '-') << " ";
    }
    cout << endl;


    return 0;
}