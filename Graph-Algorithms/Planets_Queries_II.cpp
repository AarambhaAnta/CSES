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
const ll LOG = 20;
const ll maxn = 2e5 + 5;
ll up[maxn][LOG];
ll len[maxn];
bool visited[maxn];

ll jump(ll x, ll k) {
    if (k < 0)
        return -1;
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            x = up[x][i];
        }
    }
    return x;
}
void dfs(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    dfs(up[u][0]);
    len[u] = len[up[u][0]] + 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        cin >> up[i][0];
    }

    for (ll i = 1; i < LOG; i++) {
        for (ll j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    for (ll u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;

        // case 1: a->...->b
        ll ans = -1;
        ll cycle_start = jump(a, len[a]);
        if (jump(a, len[a] - len[b]) == b) {
            ans = len[a] - len[b];

        } else if (jump(cycle_start, len[cycle_start] - len[b]) == b) {
            ans = len[cycle_start] - len[b] + len[a];
        }
        cout << ans << "\n";
    }

    return 0;
}