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
const ll maxn = 2e5 + 5;
const ll LOG = 30;
ll succ[LOG][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> succ[0][i];
    }

    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            succ[i][j] = succ[i - 1][succ[i - 1][j]];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                x = succ[i][x];
            }
        }
        cout << x << endl;
    }

    return 0;
}