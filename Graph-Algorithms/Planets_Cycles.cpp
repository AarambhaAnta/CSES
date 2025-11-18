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

int teleporter[maxn];
bool visited[maxn];
bool cycle[maxn];
int answer[maxn];
vector<int> rev_g[maxn];

pair<int, int> find_cycle(int x) {
    int a = x;
    int b = teleporter[x];
    while (a != b) {
        a = teleporter[a];
        b = teleporter[teleporter[b]];
    }
    int size = 0;
    do {
        size++;
        cycle[a] = true;
        a = teleporter[a];
    } while (a != b);
    return {a, size};
}
void dfs(int u, int parent_answer) {
    if (visited[u])
        return;
    visited[u] = true;

    answer[u] = parent_answer;
    if (!cycle[u])
        ++answer[u];
    for (int v : rev_g[u]) {
        dfs(v, answer[u]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int u = 1; u <= n; u++) {
        cin >> teleporter[u];
        rev_g[teleporter[u]].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            auto [x, size] = find_cycle(u);
            dfs(x, size);
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << answer[u] << " ";
    }
    
    return 0;
}